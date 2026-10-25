class Solution {
private:
    bool dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false;
        }
        
        if (grid[r][c] == 1) {
            return true;
        }
        
       
        grid[r][c] = 1;
        
        
        bool up = dfs(grid, r - 1, c, m, n);
        bool down = dfs(grid, r + 1, c, m, n);
        bool left = dfs(grid, r, c - 1, m, n);
        bool right = dfs(grid, r, c + 1, m, n);
        
        
        return up && down && left && right;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int closed_islands = 0;
        
       
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0) {
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j, m, n)) {
                        closed_islands++;
                    }
                }
            }
        }
        
        return closed_islands;
    }
};