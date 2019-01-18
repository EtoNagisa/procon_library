#include "bits/stdc++.h"

struct CRT {
public:
	std::pair<long long, long long> calc(const std::vector<long long> &r, const std::vector<long long> &m) {
		assert(r.size() == m.size());
		long long R = 0, M = 1;
		for (int i = 0; i < r.size(); ++i) {
			std::pair<long long, long long> p = calc(R, M, r[i], m[i]);
			if (p.second == -1)return std::make_pair(0, -1);
			R = p.first;
			M = p.second;
		}
		return std::make_pair(R, M);
	}
private:
	long long extGcd(long long a, long long b, long long &p, long long &q) {
		if (b == 0) {
			p = 1;
			q = 0;
			return a;
		}
		long long d = extGcd(b, a%b, q, p);
		q -= (a / b)*p;
		return d;
	}
	// returns {r,m} : x = r mod m
	std::pair<long long, long long > calc(long long r1, long long m1, long long r2, long long m2) {
		long long p, q;
		long long d = extGcd(m1, m2, p, q);
		if ((r2 - r1) % d != 0)return std::make_pair(0, -1);
		long long M = m1 / d * m2;
		return std::make_pair((r1 + ((r2 - r1) / d) *p % M*m1%M + M) % M, M);
	}
};