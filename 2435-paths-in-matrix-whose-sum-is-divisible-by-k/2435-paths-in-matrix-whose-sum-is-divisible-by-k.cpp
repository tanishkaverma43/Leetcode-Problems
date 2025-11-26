class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        vector<vector<int>> newdp(n, vector<int>(k, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) fill(newdp[j].begin(), newdp[j].end(), 0);
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                if (i == 0 && j == 0) {
                    newdp[0][ val % k ] = 1;
                    continue;
                }
                for (int r = 0; r < k; ++r) {
                    long long ways = 0;
                    if (i > 0) ways += dp[j][r];
                    if (j > 0) ways += newdp[j-1][r];
                    if (ways == 0) continue;
                    int new_r = (r + val) % k;
                    newdp[j][new_r] = (newdp[j][new_r] + ways) % MOD;
                }
            }
            dp.swap(newdp);
        }

        return dp[n-1][0];
    }
};