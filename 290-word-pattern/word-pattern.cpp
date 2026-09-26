class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        int low = 0, high = 0, i = 0;
        map<char,string> mpp;
        set<string> st;

        while(high <= s.length())
        {
            if(high == s.length() || s[high] == ' ')
            {
                string temp = s.substr(low, high - low);
                low = high + 1;

                // More words than pattern characters
                if(i >= pattern.length())
                    return false;

                if(mpp.find(pattern[i]) == mpp.end())
                {
                    if(st.find(temp) != st.end())
                        return false;

                    st.insert(temp);
                    mpp[pattern[i]] = temp;
                }
                else
                {
                    if(mpp[pattern[i]] != temp)
                        return false;
                }

                i++;
            }

            high++;
        }

        // More pattern characters than words
        if(i != pattern.length())
            return false;

        return true;
    }
};