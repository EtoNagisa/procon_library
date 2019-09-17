#include "bits/stdc++.h"

struct RARS {
  struct t1 {
    long long val, size;
    constexpr t1(long long v, long long s) : val(v), size(s) {}
  };
  using t2 = long long;
  static constexpr t1 id1() {
    return t1(0, 0);
  }
  static constexpr t2 id2() {
    return 0ll;
  }
  static t1 op1(const t1 &a, const t1 &b) {
    return t1(a.val + b.val, a.size + b.size);
  }
  static t1 op2(const t1 &a, const t2 &b) {
    return t1(a.val + b * a.size, a.size);
  }
  static t2 op3(const t2 &a, const t2 &b) {
    return a + b;
  }
};

struct RARm {
  using t1 = long long;
  using t2 = long long;
  static constexpr t1 id1() {
    return std::numeric_limits<t1>::max() / 2;
  }
  static constexpr t2 id2() {
    return 0ll;
  }
  static t1 op1(const t1 &a, const t1 &b) {
    return std::min(a, b);
  }
  static t1 op2(const t1 &a, const t2 &b) {
    return a + b;
  }
  static t2 op3(const t2 &a, const t2 &b) {
    return a + b;
  }
};

struct RARM {
  using t1 = long long;
  using t2 = long long;
  static constexpr t1 id1() {
    return std::numeric_limits<t1>::min() / 2;
  }
  static constexpr t2 id2() {
    return 0ll;
  }
  static t1 op1(const t1 &a, const t1 &b) {
    return std::max(a, b);
  }
  static t1 op2(const t1 &a, const t2 &b) {
    return a + b;
  }
  static t2 op3(const t2 &a, const t2 &b) {
    return a + b;
  }
};
template <typename M> struct LazySegmentTree {

  int n;
  using T1 = typename M::t1;
  using T2 = typename M::t2;
  std::vector<T1> nodes;
  std::vector<T2> lazy;

  LazySegmentTree(std::vector<T1> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz)
      n *= 2;
    nodes.resize(2 * n - 1, M::id1());
    lazy.resize(2 * n - 1, M::id2());

    for (int i = 0; i < sz; i++)
      nodes[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      nodes[i] = M::op1(nodes[i * 2 + 1], nodes[i * 2 + 2]);
  }

  void eval(int k, int l, int r) {
    if (lazy[k] != M::id2()) {
      nodes[k] = M::op2(nodes[k], lazy[k]);
      if (r - l > 1) {
        lazy[2 * k + 1] = M::op3(lazy[2 * k + 1], lazy[k]);
        lazy[2 * k + 2] = M::op3(lazy[2 * k + 2], lazy[k]);
      }
      lazy[k] = M::id2();
    }
  }
  void update(int a, int b, T2 x) {
    update(a, b, x, 0, 0, n);
  }
  T1 query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

private:
  void update(int a, int b, T2 x, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b) {
      lazy[k] = M::op3(lazy[k], x);
      eval(k, l, r);
    } else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      nodes[k] = M::op1(nodes[2 * k + 1], nodes[2 * k + 2]);
    }
  }

  T1 query(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return M::id1();
    eval(k, l, r);
    if (a <= l && r <= b)
      return nodes[k];
    return M::op1(query(a, b, 2 * k + 1, l, (l + r) / 2),
                  query(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};