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

//////////////////////////////////////////////////


///n=1はバグる！！！///
struct LCA {
	int n;
	vvi parent;//parent[i][k]:2^k-th parent of i-th node
	vi depth;//depth[i]:depth of i-th node

	LCA(const vvi &graph, const int  N, int root)
		:n(N), depth(N), parent(n, vi(log2(n) + 1, -1)) {
		dfs(graph, root, -1, 0);
		REP(k, int(log2(n))) {
			REP(i, n) {
				if (parent[i][k] != -1) {
					parent[i][k + 1] = parent[parent[i][k]][k];
				}
			}
		}
	}

	void dfs(const vvi &graph, int v, int p, int d) {//graph,current node,previous node,depth
		depth[v] = d;
		parent[v][0] = p;
		REP(i, graph[v].size()) {
			if (graph[v][i] != p)dfs(graph, graph[v][i], v, d + 1);
		}
	}

	int get(int v, int w) {//lca of v and w
		if (depth[v] < depth[w])swap(v, w);
		int dif = depth[v] - depth[w];
		REP(i, log2(n) + 1) {
			if (1 << i&dif)v = parent[v][i];
		}
		if (v == w)return v;
		RREP(i, log2(n)) {
			if (parent[v][i] != parent[w][i] && parent[v][i] != -1) {
				v = parent[v][i];
				w = parent[w][i];
			}
		}
		return parent[v][0];
	}
};
