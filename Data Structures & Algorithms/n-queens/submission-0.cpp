class Solution {
public:

    bool isSafe(int row,int col,vector<string>& board,int n)
    {
        //check col
        for(int i = 0;i < row;i++)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }

        //now diags
        int i = row;
        int j = col;

        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }

            i--;
            j--;
        }
        i = row;
        j = col;

        while(i >= 0 && j < n)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }

            i--;
            j++;
        }

        return true;
    }

    void helper(int row,vector<string>& board,vector<vector<string>>& res,int n)
    {
        //bc

        if(row == n)
        {
            res.push_back(board);
            return;
        }

        for(int col = 0;col < n;col++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col] = 'Q';

                helper(row + 1,board,res,n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> res;

        vector<string> board(n,string(n,'.'));

        helper(0,board,res,n);

        return res;
    }
};