#include "bits/stdc++.h"

// 0-indexed
class FenwickTree {
public:
  FenwickTree(int _n) : n(_n) { v.resize(_n + 1, 0); }

  void add(int pos, long long val) {
    pos++;
    for (int i = pos; i <= n; i += i & (-i))
      v[i] += val;
  }

  // sum [l, r]
  long long sum(int l, int r) { return sum(r) - sum(l - 1); }

  // sum [0,pos]
  long long sum(int pos) {
    pos++;
    long long ret = 0;
    for (int i = pos; i > 0; i -= i & (-i))
      ret += v[i];
    return ret;
  }

private:
  int n;
  std::vector<long long> v;
};