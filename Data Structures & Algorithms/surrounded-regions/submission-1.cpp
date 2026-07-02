class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i, int j, vector<vector<char>>& board, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        if (board[i][j] != 'O')
            return;

        board[i][j] = '#';
        for (auto& v : dirs) {
            dfs(i + v[0], j + v[1], board, n, m);
        }
    }

    void solve(vector<vector<char>>& board) {
        // for bordercells if O then dfs and make them #
        int n = board.size();
        int m = board[0].size();

        for (int j = 0; j < m; j++) {
            dfs(0, j, board, n, m);
            dfs(n - 1, j, board, n, m);
        }

        for (int i = 1; i < n - 1; i++) {
            dfs(i, 0, board, n, m);
            dfs(i, m - 1, board, n, m);
        }

        // now if 'O' make them 'X'
        // and '#' into 'O'

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
