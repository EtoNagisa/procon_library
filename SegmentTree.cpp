#include "bits/stdc++.h"


struct RMQ {
	using t = long long;
	const static t id = std::numeric_limits<t>::min();
	static t f(const t &a, const t &b) {
		return std::max(a, b);
	}
};

struct RmQ {
	using t = long long;
	const static t id = std::numeric_limits<t>::max();
	static t f(const t &a, const t &b) {
		return std::min(a, b);
	}
};


template <typename M>
struct SegmentTree {
	int n;
	using T = typename M::t;
	function<T(T, T)> f = M::f;
	T id = M::id;
	std::vector<T> nodes;

	SegmentTree(std::vector<T> v) {
		int sz = (int)v.size();
		n = 1; while (n < sz) n *= 2;
		nodes.resize(2 * n - 1, id);
		for (int i = 0; i < sz; i++) nodes[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--) nodes[i] = f(op1(nodes[i * 2 + 1], nodes[i * 2 + 2]));
	}
	SegmentTree(int _n) {
		n = 1;
		while (n < _n)n *= 2;
		nodes.resize(2 * n - 1, id);
	}
	void update(int k, T a) {
		k += n - 1;
		nodes[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			nodes[k] = f(nodes[2 * k + 1], nodes[2 * k + 2]);
		}
	}
	T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
private:
	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return id;
		if (a <= l && r <= b)return nodes[k];
		else {
			T vl = query(a, b, 2 * k + 1, l, (r + l) / 2),
				vr = query(a, b, 2 * k + 2, (r + l) / 2, r);
			return f(vl, vr);
		}
	}
};
