#include "bits/stdc++.h"

std::vector<long long> lis(const std::vector<long long> &v) {
	int n = (int)v.size();
	std::vector<int> prev(n, -1);
	std::vector<long long> dp(n + 1, std::numeric_limits<long long>::max());
	std::vector<int> pos(n + 1, -1);
	for (int i = 0; i < n; ++i) {
		int c = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();//lower:strongly increasing
		//int c = upper_bound(dp.begin(),dp.end(), v[i]) - dp.begin();// upper:weakly increasing
		pos[c] = i;
		dp[c] = v[i];
		if (c != 0)prev[i] = pos[c - 1];
	}

	std::vector<long long> ret;

	int p = pos[lower_bound(dp.begin(), dp.end(), std::numeric_limits<long long>::max()) - dp.begin() - 1];


	while (p != -1) {
		ret.push_back(v[p]);
		p = prev[p];
	}
	std::reverse(ret.begin(),ret.end());
	return ret;

}