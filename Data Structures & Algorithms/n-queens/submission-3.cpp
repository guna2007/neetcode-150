class Solution {
public:

    unordered_set<int> col;
    unordered_set<int> posdiag;
    unordered_set<int> negdiag;

    void helper(int r, vector<string>& board, vector<vector<string>>& res, int n)
    {
        //bc
        if(r == n)
        {
            res.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++)
        {
            if(col.count(c) || posdiag.count(r + c) || negdiag.count(r - c))
            {
                continue;
            }

            board[r][c] = 'Q';

            col.insert(c);
            posdiag.insert(r + c);
            negdiag.insert(r - c);

            helper(r + 1, board, res, n);

            board[r][c] = '.';

            col.erase(c);
            posdiag.erase(r + c);
            negdiag.erase(r - c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        //recursion is like moving rows r+1 and backtracking each in column for a valid pos
        //for that 3 sets col,posdiag,negdiag as global and loic for issafe to check any queen in same
        //col or diags
        //loop backtracking logic looping through cols ,if safe then change string
        //then next row, backtrack by again changing, updating sets

        //issafe logic is checking col no is contained in set and if r-c is constant r+c is k
        //like that by storing that val

        vector<vector<string>> res;

        vector<string> board(n, string(n, '.'));

        helper(0, board, res, n);

        return res;
    }
};