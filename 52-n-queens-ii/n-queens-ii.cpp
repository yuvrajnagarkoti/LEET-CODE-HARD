class Solution
{
public:

    bool check(vector<int> place,int row,int col)
    {
        for(int r=row-1;r>=0;r--)
        {
            int c=place[r];
            if( c==col || abs(row-r) == abs(col-c))
            {
                return false;
            }
        }
        return true;
    }

    int ans=0;
    void solve(vector<int> place,int row)
    {
        if(row>=place.size())
        {
            ans++;
            return;
        }
        for(int i=0;i<place.size();i++)
        {
            if(check(place,row,i))
            {
                place[row] = i;
                solve(place,row+1);
                place[row] = -1;
            }
        }
    }

    int totalNQueens(int n)
    {
        vector<int> place(n,-1);
        solve(place,0);
        return ans;
    }

};