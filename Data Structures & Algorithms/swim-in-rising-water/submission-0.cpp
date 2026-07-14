class Solution {
public:

    int INF = 1e9;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    int swimInWater(vector<vector<int>>& grid) {
        // dijkstra on grid
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // pq of minheap with {dist,i,j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        // now like normal dijkstra
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int d = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(d > dist[i][j])
                continue;

            // return the dist in n-1,n-1 when that node is popped
            if(i == n-1 && j == n-1)
                return d;

            // exploring in all 4 dirs if possible
            for(auto dir : dirs)
            {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni < 0 || nj < 0 || ni >= n || nj >= n)
                    continue;

                int newDist = max(d, grid[ni][nj]);

                // checking if relaxed and push into pq
                if(newDist < dist[ni][nj])
                {
                    dist[ni][nj] = newDist;
                    pq.push({newDist, ni, nj});
                }
            }
        }

        return -1;
    }
};