class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& vis)
    {
        int n = heights.size();
        int m = heights[0].size();

        if(vis[i][j])
            return;

        vis[i][j] = true;

        for(auto &d : dirs)
        {
            int nr = i + d[0];
            int nc = j + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if(heights[nr][nc] < heights[i][j])
                continue;

            dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //logic is to take 2 sets set1,set2 with i,j vecs
        //do dfs for each border of pacific grid doing backtracking in 4 dirs
        //but if neig >= curr
        //add them into set1

        //repeat for atlantic into set2


        //then common ones push into res and return

        //implement a func for dfs with state as pacific or atlantic
        //another for returning common ones, use gloabal vars for easy


        //&&&&&&&&&&&@@@@@@@@@
        //but i made wrong in backttracking dfs, as its unnec
        //as i can make it peremantnt, 

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m,false));
        vector<vector<bool>> atlantic(n, vector<bool>(m,false));

        // Pacific
        for(int j = 0; j < m; j++)
            dfs(0, j, heights, pacific);

        for(int i = 0; i < n; i++)
            dfs(i, 0, heights, pacific);

        // Atlantic
        for(int j = 0; j < m; j++)
            dfs(n-1, j, heights, atlantic);

        for(int i = 0; i < n; i++)
            dfs(i, m-1, heights, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};