class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // toposort kahns algo
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> indegree(n, vector<int>(m, 0));

        // calc indegree
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                for (auto& v : dirs) {
                    if (!(r + v[0] >= n || c + v[1] >= m || r + v[0] < 0 ||
                          c + v[1] < 0 ||
                          matrix[r + v[0]][c + v[1]] >= matrix[r][c]))
                        indegree[r][c]++;
                }
            }
        }

        // push all {r,c} into queue
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (indegree[i][j] == 0)
                    que.push({i, j});
            }
        }

        int ans = 0;

        while (!que.empty()) {
            int sz = que.size();
            

            while (sz--) {
                auto [r, c] = que.front();
                que.pop();

                for (auto& v : dirs) {
                    if (!(r + v[0] >= n || c + v[1] >= m || r + v[0] < 0 ||
                          c + v[1] < 0 ||
                          matrix[r + v[0]][c + v[1]] <= matrix[r][c])) {

                        indegree[r + v[0]][c + v[1]]--;

                        if (indegree[r + v[0]][c + v[1]] == 0)
                            que.push({r + v[0], c + v[1]});
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};