class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        if(s.length() != t.length())
            return false;

        map<char,char> mpp;
        set<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(mpp.find(s[i]) == mpp.end())
            {
                mpp[s[i]] = t[i];
                if(st.find(t[i]) != st.end())
                    return false;

                st.insert(t[i]);
            }
            else
            {
                if(mpp[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};