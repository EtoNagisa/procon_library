#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define PB(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007

using namespace std;

const double PI = acos(-1);

typedef complex<double> Comp;

bool ispowof2(int n) {
	int a = 1;
	while (n >= a) {
		if (n == a) {
			return true;
		}
		a <<= 1;
	}
	return false;
}

//Cooley-Tukey,radix-2,decimation-in-Frequency,in-place
void fft(vector<Comp> &v) {
	int n = v.size();
	assert(ispowof2(n));

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
void ifft(vector<Comp> &v) {
	int n = v.size();
	assert(ispowof2(n));
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

void convolution(vector<Comp> &P, vector<Comp> &Q) {
	fft(P);
	fft(Q);
	for (int i = 0; i < P.size(); i++) P[i] *= Q[i];
	ifft(P);
}

int main() {
	int n;
	cin >> n;
	vector<Comp> a(1 << 18, 0), b(1 << 18, 0);
	REP(i, n) {
		cin >> a[i + 1] >> b[i + 1];
	}
	convolution(a, b);
	REP(i, 2 * n) {
		cout << int(a[i + 1].real() + 0.1) << endl;
	}
}