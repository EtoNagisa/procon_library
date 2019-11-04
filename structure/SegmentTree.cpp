#include "bits/stdc++.h"

struct RMQ {
  using t = long long;
  constexpr static t id() { return std::numeric_limits<t>::min(); }
  static t op(const t &a, const t &b) { return std::max(a, b); }
};

struct RmQ {
  using t = long long;
  constexpr static t id() { return std::numeric_limits<t>::max(); }
  static t op(const t &a, const t &b) { return std::min(a, b); }
};

template <typename M>
struct SegmentTree {
  int n;
  using T = typename M::t;
  std::vector<T> nodes;

  SegmentTree(std::vector<T> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    nodes.resize(2 * n - 1, M::id());
    for (int i = 0; i < sz; i++) nodes[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      nodes[i] = M::op(nodes[i * 2 + 1], nodes[i * 2 + 2]);
  }
  SegmentTree(int _n) {
    n = 1;
    while (n < _n) n *= 2;
    nodes.resize(2 * n - 1, M::id());
  }
  void update(int k, T a) {
    k += n - 1;
    nodes[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      nodes[k] = M::op(nodes[2 * k + 1], nodes[2 * k + 2]);
    }
  }
  T get(int k) { return nodes[k + n - 1]; }
  T query(int a, int b) { return query(a, b, 0, 0, n); }

 private:
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return M::id();
    if (a <= l && r <= b)
      return nodes[k];
    else {
      T vl = query(a, b, 2 * k + 1, l, (r + l) / 2),
        vr = query(a, b, 2 * k + 2, (r + l) / 2, r);
      return M::op(vl, vr);
    }
  }
};