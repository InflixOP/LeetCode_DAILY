class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}};
    int solve(auto& grid, auto& dp, int k, int i, int j, int sum) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i == m-1 && j == n-1) {
            if (sum == 0)
                return 1;
            return 0;
        }

        if (dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        }
        
        int ans = 0;
        for (auto& dir : dirs) {
            int new_i = i+ dir[0];
            int new_j = j + dir[1];
            if (new_i < m && new_j<n) {
                int new_sum = (sum + grid[new_i][new_j]%k)%k;
                int temp = solve(grid, dp, k, new_i, new_j, new_sum);
                ans = (ans + temp)%mod;
            }
        }

        return dp[i][j][sum] = ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        int sum = grid[0][0] % k;
        return solve(grid, dp, k, 0, 0, sum);
    }
};