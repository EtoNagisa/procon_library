#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
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
///(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)///
struct RMQ {
	using t = int;
	const static t id = -INF;
	static t f(const t &a, const t &b) {
		return max(a, b);
	}
};


template <typename M>
struct SegmentTree {
	int n;
	using T = typename M::t;
	function<T(T, T)> f = M::f;
	T id = M::id;
	vector<T> nodes;
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
