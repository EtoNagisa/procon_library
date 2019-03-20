#include "bits/stdc++.h"


struct RMQ {
	using t = long long;
	constexpr static t id() {
		return std::numeric_limits<t>::min() / 2;
	}
	static t f(const t &a, const t &b) {
		return std::max(a, b);
	}
};

struct RmQ {
	using t = long long;
	constexpr static t id() {
		return std::numeric_limits<t>::max();
	}
	static t f(const t &a, const t &b) {
		return std::min(a, b);
	}
};


template <typename M>
struct SegmentTree {
	int n;
	using T = typename M::t;
	std::vector<T> nodes;

	SegmentTree(int _n) {
		_n = minp(_n);
		n = _n;
		nodes.resize(2 * n - 1, M::id());
	}
	void update(int k, T a) {
		k += n - 1;
		nodes[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			nodes[k] = M::f(nodes[2 * k + 1], nodes[2 * k + 2]);
		}
	}
	T get(int k) {
		return nodes[k + n - 1];
	}
	T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
private:
	int minp(int n) {
		int ret = 1;
		while (ret < n)ret *= 2;
		return ret;
	}
	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return M::id();
		if (a <= l && r <= b)return nodes[k];
		else {
			T vl = query(a, b, 2 * k + 1, l, (r + l) / 2),
				vr = query(a, b, 2 * k + 2, (r + l) / 2, r);
			return M::f(vl, vr);
		}
	}
};
