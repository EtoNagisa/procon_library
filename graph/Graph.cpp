#include "bits/stdc++.h"

struct Edge {
  int from;
  int to;
  long long weight;
};
typedef std::vector<Edge> Edges;
typedef std::vector<Edges> Graph;
typedef std::pair<long long, int> P;

std::vector<long long> dijkstra(const Graph &g, int src) {
  std::vector<long long> d(g.size(), std::numeric_limits<long long>::max());
  d[src] = 0;
  // vector<int> prev(g.size());
  std::priority_queue<P, std::vector<P>, std::greater<P>> q;
  q.push({0, src});
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    int v = p.second;
    if (p.first > d[v]) continue;
    for (int i = 0; i < (int)g[v].size(); ++i) {
      Edge e = g[v][i];
      if (d[e.to] > d[v] + e.weight) {
        d[e.to] = d[v] + e.weight;
        q.push({d[e.to], e.to});
        // prev[e.to] = v;
      }
    }
  }
  return d;
}
