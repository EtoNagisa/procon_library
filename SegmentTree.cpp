#include "bits/stdc++.h"


struct RMQ {
	using t = int;
	const static t id = std::numeric_limits<t>::min();
	static t f(const t &a, const t &b) {
		return std::max(a, b);
	}
};


template <typename M>
struct SegmentTree {
	int n;
	using T = typename M::t;
	function<T(T, T)> f = M::f;
	T id = M::id;
	std::vector<T> nodes;
	SegmentTree(int _n) {
		_n = minp(_n);
		n = _n;
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
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return id;
		if (a <= l && r <= b)return nodes[k];
		else {
			int vl = query(a, b, 2 * k + 1, l, (r + l) / 2),
				vr = query(a, b, 2 * k + 2, (r + l) / 2, r);
			return f(vl, vr);
		}
	}
private:
	int minp(int n) {
		int ret = 1;
		while (ret < n)ret *= 2;
		return ret;
	}
};
