#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v),v.end()));
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
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
//////////////////////////////////////
class Kitamasa {
	int k;
	vl cor;
public:
	Kitamasa(int K, vl v) :k(K), cor(v) {}

	void adv(vl &v) {
		vl ret(k);
		ret[0] = 0;
		REP(i, k - 1) {
			ret[i + 1] = v[i];
		}
		REP(i, k) {
			ret[i] += cor[i] * v[k - 1];
			ret[i] %= MOD;
		}
		v = ret;
	}

	void dbl(vl &v) {
		vl tmp = v, ret(k, 0);
		REP(i, k) {
			REP(j, k) {
				ret[j] += tmp[j] * v[i];
				ret[j] %= MOD;
			}
			adv(tmp);
		}
		v = ret;;
	}

	vl calc(int n) {
		vl ret(k, 0);
		ret[0] = 1;
		int j = 63;
		while (!(1ll << j&n))j--;
		RREP(i, j + 1) {
			dbl(ret);
			if (n&(1ll << i))adv(ret);
		}
		return ret;
	}
};