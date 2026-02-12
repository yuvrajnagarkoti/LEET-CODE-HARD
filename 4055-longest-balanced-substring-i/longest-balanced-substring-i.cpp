class Solution
{
public:

    bool isbalanced(const unordered_map<char,int>& mpp)
    {
        if (mpp.empty())
            return false;

        int count = mpp.begin()->second;
        for (const auto& it : mpp)
        {
            if (it.second != count)
                return false;
        }
        return true;
    }

    int longestBalanced(string s)
    {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> mpp;
            for(int j=i;j<n;j++)
            {
                mpp[s[j]]++;
                if( isbalanced(mpp) )
                {
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};