class Solution {
public:

    vector<int> vis;
    vector<int> path;
    int cnt = 0;

    bool dfs(int node,int parent,vector<vector<int>>& adj)
    {
        vis[node] = 1;
        cnt++;

        for(auto nei : adj[node])
        {
            if(vis[nei] == 0)
            {
                if(dfs(nei,node,adj)) return true;
            }
            else if(nei != parent)
            {
                return true;
            }
            
        }

        return false;
    }



    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vis.resize(n,0);
        path.resize(n,0);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        bool ans = dfs(0,-1,adj);

        if(!ans && (cnt==n)) return true;
        return false;

    }
};
