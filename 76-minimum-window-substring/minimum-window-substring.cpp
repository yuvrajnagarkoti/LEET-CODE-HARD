class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        if (t.length() > n) return "";

        vector<int> need(256, 0);
        for (char c : t)
            need[c]++;

        int required = t.length();
        int low = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int high = 0; high < n; high++)
        {
            // expand window
            if (need[s[high]] > 0)
                required--;
            need[s[high]]--;

            // shrink window while valid
            while (required == 0)
            {
                int currLen = high - low + 1;
                if (currLen < minLen)
                {
                    minLen = currLen;
                    start = low;
                }

                need[s[low]]++;
                if (need[s[low]] > 0)
                    required++;
                low++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};