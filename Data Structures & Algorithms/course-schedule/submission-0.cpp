class Solution {
public:
    vector<int> visited;
    vector<int> pathVis;

    bool dfs(int num, vector<vector<int>>&adj)
    {
        visited[num] = 1;
        pathVis[num] = 1;

        for(int i = 0;i < adj[num].size();i++)
        {
            int next = adj[num][i];

            if(visited[next] == 0)
            {
                if(dfs(next,adj))
                    return true;
            }
            else if(pathVis[next])
            {
                return true;
            }
        }

        pathVis[num] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<vector<int>> adj(n);
        visited.resize(n,0);
        pathVis.resize(n,0);

        //logic is to run dfs after adjmatrix, then if we visit the visited node when dfspath
        //false

        for(auto &v : graph)
        {
            adj[v[1]].push_back(v[0]);
        }

        bool flag = 0;

        for(int i = 0;i < n;i++)
        {
            if(visited[i] == 0)
            {
                flag = dfs(i,adj);

                if(flag)
                    return false;
            }
        }

        return true;
    }
};