#include "bits/stdc++.h"

class Kitamasa {
	int k;
	static constexpr int m = 1e9 + 7;
	std::vector<long long> cor;
public:
	Kitamasa(std::vector<long long> cor_)
		:k(cor_.size()), cor(cor_)
	{}

	void adv(std::vector<long long> &v) {
		std::vector<long long> ret(k);
		ret[0] = 0;
		for (int i = 0; i < k - 1; ++i) {
			ret[i + 1] = v[i];
		}
		for (int i = 0; i < k; ++i) {
			ret[i] += cor[i] * v[k - 1];
			ret[i] %= m;
		}
		v = ret;
	}

	void dbl(std::vector<long long> &v) {
		std::vector<long long> tmp = v, ret(k, 0);
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < k; ++j) {
				ret[j] += tmp[j] * v[i];
				ret[j] %= m;
			}
			adv(tmp);
		}
		v = ret;;
	}

	long long calc(int n) {
		std::vector<long long> ret(k, 0);
		ret[0] = 1;
		int j = 63;
		while (!(1ll << j & n))j--;
		for (int i = j; i >= 0; --i) {
			dbl(ret);
			if (n&(1ll << i))adv(ret);
		}
		long long ans = 0;
		for (int i = 0; i < k; ++i) {
			ans += cor[i] * ret[i];
			ans %= m;
		}
		return ans;
	}
};