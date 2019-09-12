#include "bits/stdc++.h"

template <typename T> using Matrix = std::vector<std::vector<T>>;

template <typename T> Matrix<T> add(const Matrix<T> &a, const Matrix<T> &b) {
  int n = a.size(), m = a[0].size();
  assert(a.size() == b.size() && a[0].size() == b[0].size());
  Matrix<T> res(n, std::vector<long long>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res[i][j] = a[i][j] + b[i][j];
    }
  }
  return res;
}

template <typename T>
Matrix<T> mult(const Matrix<T> &a,
               const Matrix<T> &b) { // a:n*m matrix,b:m*l matrix
  int n = a.size(), m = a[0].size(), l = b[0].size();
  Matrix<T> res(n, std::vector<long long>(l, 0));
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < m; ++k) {
      for (int j = 0; j < l; ++j) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}

template <typename T> Matrix<T> fact(const Matrix<T> &a, long long n) {
  Matrix<T> e(a.size(), std::vector<long long>(a.size(), 0));
  for (int i = 0; i < (int)a.size(); ++i) {
    e[i][i] = 1;
  }
  while (n >= 1) {
    if (n & 1)
      e = mult(e, a);
    a = mult(a, a);
    n /= 2;
  }
  return e;
}