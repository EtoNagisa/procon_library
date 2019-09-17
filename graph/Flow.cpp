
#include "bits/stdc++.h"

struct Edge {
  int to;
  long long cap;
  int rev;
  long long cost;
};
typedef std::vector<Edge> Edges;
typedef std::vector<Edges> Graph;

struct MaxFlow {
  Graph g;
  std::vector<int> level, iter;
  MaxFlow(int n) {
    level.resize(n);
    iter.resize(n);
    g.resize(n);
  }
  void add_edge(int from, int to, int cap, int cost = 0) {
    g[from].push_back(Edge{to, cap, (int)g[to].size(), cost});
    g[to].push_back(Edge{from, 0, (int)g[from].size() - 1, -cost});
  }

  void bfs(int s) {
    std::fill(level.begin(), level.end(), -1);
    std::queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < (int)g[v].size(); i++) {
        Edge &e = g[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }
  long long dfs(int v, int t, long long f) {
    if (v == t)
      return f;
    for (int &i = iter[v]; i < (int)g[v].size(); i++) {
      Edge &e = g[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        long long d = dfs(e.to, t, std::min(f, (long long)e.cap));
        if (d > 0) {
          e.cap -= d;
          g[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  long long max_flow(int s, int t) {
    long long flow = 0;
    for (;;) {
      bfs(s);
      if (level[t] < 0)
        return flow;
      std::fill(iter.begin(), iter.end(), 0);
      long long f;
      while ((f = dfs(s, t, std::numeric_limits<long long>::max())) > 0) {
        flow += f;
      }
    }
  }
};

/////////////////////////////////////////////////////////

struct MinCostFlow {
  using P = std::pair<long long, int>;

  int n;
  std::vector<long long> h, dist;
  std::vector<int> prevv, preve;
  Graph g;
  MinCostFlow(int n_) : n(n_) {
    h.resize(n, 0);
    dist.resize(n);
    prevv.resize(n);
    preve.resize(n);
  }

  void add_edge(int from, int to, int cap, int cost) {
    g[from].push_back(Edge{to, cap, (int)g[to].size(), cost});
    g[to].push_back(Edge{from, 0, (int)g[from].size() - 1, -cost});
  }

  long long min_cost_flow(int s, int t, long long f) {
    long long res = 0;
    while (f > 0) {
      std::priority_queue<P, std::vector<P>, std::greater<P>> que;
      std::fill_n(dist.begin(), n, std::numeric_limits<long long>::max());
      dist[s] = 0;
      que.push({0, s});
      while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first)
          continue;
        for (int i = 0; i < (int)g[v].size(); i++) {
          Edge &e = g[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            que.push({dist[e.to], e.to});
          }
        }
      }
      if (dist[t] == std::numeric_limits<long long>::max()) {
        return -1;
      }
      for (int v = 0; v < n; v++)
        h[v] += dist[v];

      long long d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = std::min(d, (long long)g[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        Edge &e = g[prevv[v]][preve[v]];
        e.cap -= d;
        g[v][e.rev].cap += d;
      }
    }
    return res;
  }
};