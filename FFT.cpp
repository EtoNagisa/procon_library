#include "bits/stdc++.h"

using real_t = long double;
typedef std::complex<real_t> Comp;
long double PI = acos(-1);
class FFT {

	//Cooley-Tukey,radix-2,decimation-in-Frequency,in-place
	static void fft(std::vector<Comp> &v) {
		int n = (int)v.size();
		for (int m = n; m >= 2; m >>= 1) {
			double deg = (-1) * 2 * PI / m;
			Comp r(cos(deg), sin(deg));
			for (int i = 0; i < n; i += m) {
				Comp w(1, 0);
				for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
					Comp t1 = v[j], t2 = v[k];
					v[j] = t1 + t2, v[k] = w * (t1 - t2);
					w *= r;
				}
			}
		}
	}

	//Cooley-Tukey,radix-2,decimation-in-time,in-place
	static void ifft(std::vector<Comp> &v) {
		int n = (int)v.size();
		for (int m = 2; m <= n; m <<= 1) {
			double deg = 2 * PI / m;
			Comp r(cos(deg), sin(deg));
			for (int i = 0; i < n; i += m) {
				Comp w(1, 0);
				for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
					Comp t1 = v[j], t2 = w * v[k];
					v[j] = t1 + t2, v[k] = t1 - t2;
					w *= r;
				}
			}
		}
		for (int i = 0; i < n; ++i) v[i] *= 1.0 / n;
	}
public:
	static std::vector<long long> convolution(const std::vector<long long> &p, const std::vector<long long> &q) {
		int n = 1;
		int a = p.size(), b = q.size();
		while (n < a + b)n <<= 1;
		std::vector<Comp> cp(n), cq(n);
		for (int i = 0; i < a; ++i)cp[i] = Comp((real_t)p[i], 0);
		for (int i = 0; i < b; ++i)cq[i] = Comp((real_t)q[i], 0);
		fft(cp);
		fft(cq);
		for (int i = 0; i < n; i++)cp[i] *= cq[i];
		ifft(cp);
		std::vector<long long> ret(n);
		for (int i = 0; i < n; ++i)ret[i] = (long long)(cp[i].real() + 0.5);
		return ret;
	}
};