class Solution
{
    public:
    vector<string> ans;
    void gen(string &s, int left, int right, int n)
    {
        if(s.size() == 2*n)
        {
            ans.push_back(s);
            return;
        }

        if(left < n)
        {
            s.push_back('(');
            gen(s, left+1, right, n);
            s.pop_back();
        }

        if(right < left)
        {
            s.push_back(')');
            gen(s, left, right+1, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string s ="";
        int left=0,right=0;
        gen(s,left,right,n);
        return ans;
    }
};