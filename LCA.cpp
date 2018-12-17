#include "bits/stdc++.h"


///n=1はバグる！！！///
struct LCA {
	int n;
	std::vector<std::vector<int>> parent;//parent[i][k]:2^k-th parent of i-th node
	std::vector<int> depth;//depth[i]:depth of i-th node

	LCA(std::vector<std::vector<int>> &graph, int _n, int root)
		:n(_n), depth(n), parent(n, std::vector<int>(log2(n) + 1, -1)) {
		dfs(graph, root, -1, 0);
		for (int k = 0; k<int(log2(n)); ++k) {
			for (int i = 0; i < n; ++i) {
				if (parent[i][k] != -1) {
					parent[i][k + 1] = parent[parent[i][k]][k];
				}
			}
		}
	}

	void dfs(const std::vector<std::vector<int>> &graph, int v, int p, int d) {//graph,current node,previous node,depth
		depth[v] = d;
		parent[v][0] = p;
		for (int i = 0; i < graph[v].size(); ++i) {
			if (graph[v][i] != p)dfs(graph, graph[v][i], v, d + 1);
		}
	}

	int get(int v, int w) {//lca of v and w
		if (depth[v] < depth[w])std::swap(v, w);
		int dif = depth[v] - depth[w];
		for (int i = 0; i < log2(n) + 1; ++i) {
			if (1 << i & dif)v = parent[v][i];
		}
		if (v == w)return v;
		for (int i = log2(n) - 1; i >= 0; --i) {
			if (parent[v][i] != parent[w][i] && parent[v][i] != -1) {
				v = parent[v][i];
				w = parent[w][i];
			}
		}
		return parent[v][0];
	}
};
