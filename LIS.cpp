#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
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
///(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)(ÅLÅEÉ÷ÅE`)///



vi lis(const vi &v) {
	int n = v.size();
	vi prev(n, -1);
	vi dp(n + 1, INF);
	vi pos(n + 1, -1);
	REP(i, n) {
		int c = lower_bound(ALL(dp), v[i]) - dp.begin();//lower:strongly increasing
		//int c = upper_bound(ALL(dp), v[i]) - dp.begin();// upper:weakly increasing
		pos[c] = i;
		dp[c] = v[i];
		if (c != 0)prev[i] = pos[c - 1];
	}

	vi ret;

	int p = pos[lower_bound(ALL(dp), INF) - dp.begin() - 1];


	while (p != -1) {
		ret.push_back(v[p]);
		p = prev[p];
	}
	reverse(ALL(ret));
	return ret;

}