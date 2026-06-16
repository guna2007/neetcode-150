class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q; 
        // stores {{row, col}, time}

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // push all initially rotten oranges into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int time = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // BFS traversal
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t); // track max time taken

            // move in 4 directions
            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                // check if valid and fresh
                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   !vis[nr][nc] && grid[nr][nc] == 1) {

                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 1;
                    grid[nr][nc] = 2; // mark as rotten
                }
            }
        }

        // check if any fresh orange still left
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};