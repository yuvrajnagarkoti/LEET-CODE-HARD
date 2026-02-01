class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
            dp[0][i] = grid[0][i];

        vector<vector<pair<int,int>>> nums(n);

        for(int i = 1; i < n; i++)
        {
            nums[i-1].clear();

            for(int j = 0; j < n; j++)
                nums[i-1].push_back({dp[i-1][j], j});

            sort(nums[i-1].begin(), nums[i-1].end());

            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(nums[i-1][k].second != j)
                    {
                        dp[i][j] = grid[i][j] +
                                   dp[i-1][ nums[i-1][k].second ];
                        break;
                    }
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
            ans = min(ans, dp[n-1][i]);

        return ans;
    }
};
