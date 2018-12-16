#include "bits/stdc++.h"
using namespace std;

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
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
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
//////////////////////////////////////////////////////

struct Edge { int from; int to; ll weight; };
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef pair<ll, int> P;

vector<ll> dijkstra(const Graph &g, int src) {
	vector<ll> d(g.size(), INF*INF);
	d[src] = 0;
	//vector<int> prev(g.size());
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ 0, src });
	while (!q.empty()) {
		auto p = q.top(); q.pop();
		ll v = p.second;
		if (p.first > d[v]) continue;
		for (int i = 0; i < g[v].size(); ++i) {
			Edge e = g[v][i];
			if (d[e.to] > d[v] + e.weight) {
				d[e.to] = d[v] + e.weight;
				q.push({ d[e.to],e.to });
				//prev[e.to] = v;
			}
		}
	}
	return d;
}
