#include "bits/stdc++.h"

template <long long mod, long long root>
class NTT {
public:
	static constexpr long long mod_pow(long long a, long long n) {
		long long res = 1;
		while (n > 0) {
			if (n & 1)res = res * a%mod;
			a = a * a%mod;
			n >>= 1;
		}
		return res;
	}

	static constexpr long long mod_inv(long long a) {
		return mod_pow(a, mod - 2);
	}
	//Cooley-Tukey,radix-2,decimation-in-Frequency,in-place
	static void fmt(std::vector<long long> &v) {
		int n = (int)v.size();
		long long h = mod_inv(mod_pow(root, (mod - 1) / n));
		for (int m = n; m >= 2; m >>= 1) {
			long long r = mod_pow(h, n / m);
			for (int i = 0; i < n; i += m) {
				long long w = 1;
				for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
					long long t1 = v[j], t2 = v[k];
					v[j] = t1 + t2;
					if (v[j] >= mod)v[j] -= mod;
					v[k] = w * (t1 - t2 + mod) % mod;
					w = w * r%mod;
				}
			}
		}
	}

	//Cooley-Tukey,radix-2,decimation-in-time,in-place
	static void ifmt(std::vector<long long> &v) {
		int n = (int)v.size();
		long long h = mod_pow(root, (mod - 1) / n);
		for (int m = 2; m <= n; m <<= 1) {
			long long r = mod_pow(h, n / m);
			for (int i = 0; i < n; i += m) {
				long long w = 1;
				for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
					long long t1 = v[j], t2 = w * v[k] % mod;
					v[j] = t1 + t2;
					if (v[j] >= mod)v[j] -= mod;
					v[k] = t1 - t2;
					if (v[k] < 0)v[k] += mod;
					w = w * r%mod;
				}
			}
		}
		long long n_inv = mod_inv(n);
		for (int i = 0; i < n; ++i) v[i] = v[i] * n_inv% mod;
	}
	static std::vector<long long> convolution(const std::vector<long long> &p, const std::vector<long long> &q) {
		int n = 1;
		int a = p.size(), b = q.size();
		while (n < a + b)n <<= 1;
		std::vector<long long> cp(n), cq(n);
		for (int i = 0; i < a; ++i)cp[i] = p[i];
		for (int i = 0; i < b; ++i)cq[i] = q[i];
		fmt(cp);
		fmt(cq);
		for (int i = 0; i < n; i++)cp[i] = cp[i] * cq[i] % mod;
		ifmt(cp);
		return cp;
	}
};
static std::vector<long long> convolution_mod(const std::vector<long long> &p, const std::vector<long long> &q, long long m) {
	constexpr long long m1 = 1224736769ll,
		m2 = 998244353ll;
	std::vector<long long> res1 = NTT<m1, 3>::convolution(p, q),
		res2 = NTT<m2, 3>::convolution(p, q);
	int sz = res1.size();
	constexpr long long minv = NTT<m2, 3>::mod_inv(m1);
	std::vector<long long> ret(sz);
	for (int i = 0; i < sz; ++i) {
		long long x0 = res1[i],
			x1 = (res2[i] - x0 + m2)*minv%m2;
		ret[i] = (x0 + x1 * m1) % m;
	}
	return ret;
}
static std::vector<long long > convolution998244353(const std::vector<long long> &p, const std::vector<long long > &q) {
	return NTT<998244353, 3>::convolution(p, q);
}