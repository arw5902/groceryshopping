#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int k, n, m;
	cin >> k >> n >> m;
	const int len = 3002;
	vector<vector<int>> groups(len);
	int weights[len], values[len];
	int group_dp[len] = {0}, dp[len] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> weights[i] >> values[i];
		groups[0].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		cin >> weights[i + n] >> values[i + n];
		groups[i].push_back(i + n);
	}
	for (int group_id = 0; group_id <= m; group_id++) {
		for (int i = 0; i < groups[group_id].size(); i++) {
			int item_index = groups[group_id][i];
			for (int capacity = k; capacity >= weights[item_index]; capacity--) {
				group_dp[capacity] = max(group_dp[capacity], dp[capacity - weights[item_index]] + values[item_index]);
			}
		}
		for (int i = 1; i <= k; i++) dp[i] = group_dp[i];
	}
	cout << group_dp[k];
}
