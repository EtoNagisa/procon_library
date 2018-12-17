#include "bits/stdc++.h"

typedef std::vector<std::vector<long long>> Matrix;

Matrix add(Matrix a, Matrix b) {
	int n = a.size(), m = a[0].size();
	assert(a.size() == b.size() && a[0].size() == b[0].size());
	Matrix res(n, std::vector<long long>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[i][j] = a[i][j] + b[i][j];
		}
	}
	return res;
}

Matrix mult(Matrix  a, Matrix b) {//a:n*m matrix,b:m*l matrix
	int n = a.size(), m = a[0].size(), l = b[0].size();
	Matrix res(n, std::vector<long long>(l, 0));
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < m; ++k) {
			for (int j = 0; j < l; ++j) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}

Matrix fact(Matrix a, int n) {
	Matrix  e(a.size(), std::vector<long long>(a.size(), 0));
	for (int i = 0; i < a.size(); ++i) {
		e[i][i] = 1;
	}
	while (n >= 1) {
		if (n & 1) e = mult(e, a);
		a = mult(a, a);
		n /= 2;
	}
	return e;
}