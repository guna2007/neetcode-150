class Solution {
public:

    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    int swimInWater(vector<vector<int>>& grid) {
        // dijkstra on grid
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // pq of minheap with {dist,i,j}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        pq.push({grid[0][0], 0, 0});

        // now like normal dijkstra
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int d = get<0>(curr);
            int i = get<1>(curr);
            int j = get<2>(curr);

            if(vis[i][j])
                continue;

            vis[i][j] = true;

            // return the dist in n-1,n-1 when that node is popped
            if(i == n-1 && j == n-1)
                return d;

            // exploring in all 4 dirs if possible
            for(auto &dir : dirs)
            {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni < 0 || nj < 0 || ni >= n || nj >= n)
                    continue;

                if(vis[ni][nj])
                    continue;

                int newDist = max(d, grid[ni][nj]);

                // push into pq
                pq.push({newDist, ni, nj});
            }
        }

        return -1;
    }
};