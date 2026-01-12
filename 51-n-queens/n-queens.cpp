class Solution
{
public:

    bool check(vector<string> board,int row,int col)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j] == 'Q')
                {
                    if( j==col || abs(row-i) == abs(col-j) )
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    vector<vector<string>> ans;
    void solve(vector<string> board,int row)
    {
        if(row >= board.size())
        {
            ans.push_back(board);
            return;
        }
        for(int j=0;j<board.size();j++)
        {
            if(check(board,row,j))
            {
                board[row][j] = 'Q';
                solve(board,row+1);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
       vector<string> board(n,string(n,'.'));
       solve(board,0);
       return ans;
    }
};