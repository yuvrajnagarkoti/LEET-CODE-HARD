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
        int start = 0;
        int anslen = INT_MAX;

        for (int high = 0; high < n; high++)
        {
            if (need[s[high]] > 0)
                required--;
            need[s[high]]--;

            while (required == 0)
            {
                int currLen = high - low + 1;
                if (currLen < anslen)
                {
                    anslen = currLen;
                    start = low;
                }

                need[s[low]]++;
                if (need[s[low]] > 0)
                    required++;
                low++;
            }
        }

        return anslen == INT_MAX ? "" : s.substr(start, anslen);
    }
};
