class Solution {
public:
    int dp[51][51][51];

    int solve(int r1, int c1, int r2, vector<vector<int>>& grid)
    {
        int c2 = r1 + c1 - r2;
        int n = grid.size();

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return INT_MIN;

        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = grid[r1][c1];
        if (r1 != r2)
            cherries += grid[r2][c2];

        int best = max({
            solve(r1+1, c1, r2+1, grid),
            solve(r1, c1+1, r2, grid),
            solve(r1+1, c1, r2, grid),
            solve(r1, c1+1, r2+1, grid)
        });

        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, grid);
        return max(ans, 0);
    }
};
