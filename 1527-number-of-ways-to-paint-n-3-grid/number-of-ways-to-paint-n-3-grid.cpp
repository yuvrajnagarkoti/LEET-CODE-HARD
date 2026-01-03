class Solution {
public:
    int numOfWays(int n)
    {
        long long mod = 1e9+7;
        long long aba = 6;
        long long abc = 6;

        for(int i=1;i<n;i++)
        {
            long long nxt_aba = (aba*3 + abc*2)%mod;
            long long nxt_abc = (aba*2 + abc*2)%mod;
            aba = nxt_aba;
            abc = nxt_abc;
        }
        return (aba+abc)%mod;
    }
};