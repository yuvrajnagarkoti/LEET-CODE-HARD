class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp = dungeon;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    if (dungeon[i][j] > 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = abs(dungeon[i][j]) + 1;
                }
                else
                {
                    int down = (i + 1 >= m) ? 1e9 : dp[i + 1][j];
                    int right = (j + 1 >= n) ? 1e9 : dp[i][j + 1];

                    int res = min(down, right) - dungeon[i][j];

                    if (res > 0)
                        dp[i][j] = res;
                    else
                        dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }
};