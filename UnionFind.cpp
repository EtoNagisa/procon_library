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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


////////////////////////////////////////////
struct UnionFind {
	vector<int> par;
	vector<int> sizes;

	UnionFind(int n) {
		par.resize(n);
		sizes.resize(n);
		REP(i, n) {
			par[i] = i;
			sizes[i] = 1;
		}
	}

	int root(int a) {
		return par[a] == a ? a : par[a] = root(par[a]);
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y)return;
		if (sizes[x] < sizes[y]) swap(x, y);

		par[y] = x;
		sizes[x] += sizes[y];
	}
	int size(int x) {
		return sizes[root(x)];
	}
};

