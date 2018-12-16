
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
struct Edge { int to, cap, rev, cost; };
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;




struct MaxFlow {
	Graph G;
	vi level, iter;
	MaxFlow(Graph g) {
		int n = g.size();
		level.resize(n);
		iter.resize(n);
		G = g;
	}
	void add_edge(int from, int to, int cap, int cost = 0) {
		G[from].push_back(Edge{ to, cap, (int)G[to].size(),cost });
		G[to].push_back(Edge{ from,0,(int)G[from].size() - 1,-cost });
	}

	void bfs(int s) {
		fill(ALL(level), -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int i = 0; i < G[v].size(); i++) {
				Edge &e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f) {
		if (v == t)return f;
		for (int &i = iter[v]; i < G[v].size(); i++) {
			Edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t) {
		int flow = 0;
		for (;;) {
			bfs(s);
			if (level[t] < 0)return flow;
			fill(ALL(iter), 0);
			int f;
			while ((f = dfs(s, t, INF)) > 0) {
				flow += f;
			}
		}
	}
};


/////////////////////////////////////////////////////////
typedef pair<int, int> P;
int V;
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

int min_cost_flow(int s, int t, int f) {
	int res = 0;
	fill_n(h, V, 0);
	while (f > 0) {
		priority_queue<P, vector<P>, greater<P>> que;
		fill_n(dist, V, numeric_limits<int>::max());
		dist[s] = 0;
		que.push({ 0,s });
		while (!que.empty()) {
			P p = que.top(); que.pop();
			int v = p.second;
			if (dist[v] < p.first)continue;
			for (int i = 0; i < G[v].size(); i++) {
				Edge &e = G[v][i];
				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push({ dist[e.to],e.to });
				}
			}
		}
		if (dist[t] == numeric_limits<int>::max()) {
			return -1;
		}
		for (int v = 0; v < V; v++)h[v] += dist[v];

		int d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d*h[t];
		for (int v = t; v != s; v = prevv[v]) {
			Edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}