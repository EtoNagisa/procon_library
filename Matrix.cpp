#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
///(LEƒÖE`)(LEƒÖE`)(LEƒÖE`)(LEƒÖE`)(LEƒÖE`)(LEƒÖE`)///

///////////////////////////////////////

typedef vvl Matrix;

Matrix add(Matrix a, Matrix b) {
	int n = a.size(), m = a[0].size();
	assert(a.size() == b.size() && a[0].size() == b[0].size());
	Matrix res(n, vl(m, 0));
	REP(i, n) {
		REP(j, n) {
			res[i][j] = a[i][j] + b[i][j];
		}
	}
	return res;
}

Matrix mult(Matrix  a, Matrix b) {//a:n*m matrix,b:m*l matrix
	int n = a.size(), m = a[0].size(), l = b[0].size();
	Matrix res(n, vl(l, 0));
	REP(i, n) {
		REP(j, l) {
			REP(k, m) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}

Matrix fact(Matrix a, int n) {
	Matrix  e(a.size(), vl(a.size(), 0));
	REP(i, a.size()) {
		e[i][i] = 1;
	}
	while (n >= 1) {
		if (n % 2 == 1) e = mult(e, a);
		a = mult(a, a);
		n /= 2;
	}
	return e;
}