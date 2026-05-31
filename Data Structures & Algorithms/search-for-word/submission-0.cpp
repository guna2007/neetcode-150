class Solution {
public:

    bool helper(int i,int j,int idx,vector<vector<char>>& board,string& word)
    {
        //bc
        if(idx == word.length())
        {
            return true;
        }

        int n = board.size();
        int m = board[0].size();

        //invalid
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx])
        {
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '#';

        bool isfound = false;

        //4 dirs
        isfound = isfound || helper(i + 1,j,idx + 1,board,word);
        isfound = isfound || helper(i - 1,j,idx + 1,board,word);
        isfound = isfound || helper(i,j + 1,idx + 1,board,word);
        isfound = isfound || helper(i,j - 1,idx + 1,board,word);

        //backtrack
        board[i][j] = ch;

        return isfound;
    }

    bool exist(vector<vector<char>>& board, string word) {
        //logic is to use helper with idx as 0 means that idx in word,word, and curr board
        //find that char in board, then run for idx+1 for all 4 dirs and mark curr with # 
        //so it cant be used again
        //now to check other occurence ,again unmark by backtrack
        //if idx gets len of word then true, if all 4 dirs cant give any useful then return false
        //we can check by a var isfound

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(helper(i,j,0,board,word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};