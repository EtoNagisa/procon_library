#include "bits/stdc++.h"

struct Scc {
	int n;
	std::vector<std::vector<int>> g,
		rg;//逆向きのグラフ
	std::vector<int> cmp,//cmp[i]:頂点iが属する強連結成分の番号
		visited,
		num;//帰りがけ順で頂点が入る
	Scc(int N) {
		n = N;
		cmp.resize(n);
		visited.resize(n);
		g.resize(n);
		rg.resize(n);
	}
	void add_edge(int from, int to) {
		g[from].push_back(to);
		rg[to].push_back(from);
	}

	void dfs(int v) {
		visited[v] = true;
		for (int i = 0; i < g[v].size(); ++i) {
			if (!visited[g[v][i]])dfs(g[v][i]);
		}
		num.push_back(v);
	}

	void rdfs(int v, int k) {
		visited[v] = true;
		cmp[v] = k;
		for (int i = 0; i < rg[v].size(); ++i) {
			if (!visited[rg[v][i]])rdfs(rg[v][i], k);
		}
	}
	int calc() {
		for (int i = 0; i < n; ++i)visited[i] = false;
		num.clear();
		for (int i = 0; i < n; ++i) {
			if (!visited[i])dfs(i);
		}
		for (int i = 0; i < n; ++i)visited[i] = false;
		int k = 0;
		for (int i = num.size() - 1; i >= 0; --i) {
			if (!visited[num[i]]) {
				rdfs(num[i], k);
				++k;
			}
		}
		return k;
	}
};