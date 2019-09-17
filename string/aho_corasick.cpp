#include "bits/stdc++.h"

struct lower_alphabet {
    static constexpr std::size_t char_size = 26;
    static constexpr char min_char = 'a';
};
struct upper_alphabet {
    static constexpr std::size_t char_size = 26;
    static constexpr char min_char = 'A';
};
struct general_char {
    static constexpr std::size_t char_size = 256;
    static constexpr char min_char = 0;
};
template <typename character>
class aho_corasick {
public:
    static constexpr size_t invalid_index = -1;
    struct PMA {
        size_t fail; // index of state correspond to fail suffix
        std::vector<size_t> next, accept;
        PMA() : fail(0), next(character::char_size, invalid_index) {}
    };
    std::vector<PMA> nodes;
    size_t cnt;
    void add_node() {
        nodes.emplace_back();
        cnt++;
    }

public:
    aho_corasick() : cnt(0) {}
    void build(const std::vector<std::string> &dict) {
        add_node();
        for (size_t i = 0; i < dict.size(); ++i) {
            size_t now = 0;
            for (size_t j = 0; j < dict[i].size(); ++j) {
                size_t t = static_cast<size_t>(dict[i][j] - character::min_char);
                if (nodes[now].next[t] == invalid_index) {
                    size_t next = size();
                    add_node();
                    nodes[now].next[t] = next;
                }
                now = nodes[now].next[t];
            }
            nodes[now].accept.push_back(i);
        }
        std::queue<size_t> q;
        for (size_t i = 0; i < character::char_size; ++i) {
            if (nodes[0].next[i] == invalid_index) {
                nodes[0].next[i] = 0;
            } else {
                nodes[nodes[0].next[i]].fail = 0;
                q.push(nodes[0].next[i]);
            }
        }
        while (!q.empty()) {
            size_t p = q.front();
            q.pop();
            for (size_t i = 0; i < character::char_size; ++i) {
                if (nodes[p].next[i] != invalid_index) {
                    size_t tmp = nodes[p].fail;
                    while (nodes[tmp].next[i] == invalid_index) {
                        tmp = nodes[tmp].fail;
                    }
                    nodes[nodes[p].next[i]].fail = nodes[tmp].next[i];
                    for (size_t ac : nodes[nodes[tmp].next[i]].accept) {
                        nodes[nodes[p].next[i]].accept.push_back(ac);
                    }
                    q.push(nodes[p].next[i]);
                }
            }
        }
    }

    size_t size() const {
        return cnt;
    }
    size_t next(size_t now, char c) const {
        size_t t = static_cast<size_t>(c - character::min_char);
        while (nodes[now].next[t] == invalid_index) now = nodes[now].fail;
        return nodes[now].next[t];
    }
    std::vector<std::vector<size_t>> match(const std::string &s) const {
        size_t now = 0;
        std::vector<std::vector<size_t>> ret(s.size());
        for (size_t i = 0; i < s.size(); ++i) {
            now = next(now, s[i]);
            for (size_t j = 0; j < nodes[now].accept.size(); ++j) {
                ret[i].push_back(nodes[now].accept[j]);
            }
        }
    }
};