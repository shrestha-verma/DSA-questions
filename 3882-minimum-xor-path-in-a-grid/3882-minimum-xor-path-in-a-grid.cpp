class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        dp[0][0].set(grid[0][0]);
        for (int j = 1; j < n; j++) {
            int val = grid[0][j];
            for (int v = 0; v < 1024; v++) {
                if (dp[0][j - 1].test(v)) {
                    dp[0][j].set(v ^ val);
                }
            }
        }
        for (int i = 1; i < m; i++) {
            int val = grid[i][0];
            for (int v = 0; v < 1024; v++) {
                if (dp[i - 1][0].test(v)) {
                    dp[i][0].set(v ^ val);
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int val = grid[i][j];
                for (int v = 0; v < 1024; v++) {
                    if (dp[i - 1][j].test(v) || dp[i][j - 1].test(v)) {
                        dp[i][j].set(v ^ val);
                    }
                }
            }
        }

        for (int v = 0; v < 1024; v++) {
            if (dp[m - 1][n - 1].test(v)) {
                return v;
            }
        }

        return 0;
    }
};