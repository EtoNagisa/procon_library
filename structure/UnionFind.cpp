#include "bits/stdc++.h"
struct UnionFind {
  std::vector<int> par;
  std::vector<int> sizes;

  UnionFind(int n) {
    par.resize(n);
    sizes.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      sizes[i] = 1;
    }
  }

  int root(int a) {
    return par[a] == a ? a : par[a] = root(par[a]);
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return;
    if (sizes[x] < sizes[y])
      std::swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];
  }
  int size(int x) {
    return sizes[root(x)];
  }
};
