class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int i = 0, j = 0, match = 0, starIdx = -1;
        while (i < s.length()) 
        {
            if (j < p.length() && (p[j] == '?' || p[j] == s[i]))
            {
                // Characters match or '?'
                i++;
                j++;
            }
            else if (j < p.length() && p[j] == '*')
            {
                // Record position of '*'
                starIdx = j;
                match = i;
                j++;
            }
            else if (starIdx != -1)
            {
                // Backtrack: match more characters with '*'
                j = starIdx + 1;
                match++;
                i = match;
            }
            else
            {
                // No match and no '*' to adjust
                return false;
            }
        }

        // Remaining characters in p must all be '*'
        while (j < p.length() && p[j] == '*')
        {
            j++;
        }
        return j == p.length();
    }
};
