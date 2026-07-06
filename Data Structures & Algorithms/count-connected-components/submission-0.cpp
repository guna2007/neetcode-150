class Solution {
public:

    vector<int> vis;

    void dfs(int node,vector<vector<int>>&adj)
    {
        if(vis[node] == 1) return;
        vis[node] = 1;

        for(auto nei : adj[node])
        {
            if(vis[nei] == 0) dfs(nei,adj);
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vis.resize(n);
        int ans = 0;

        for(auto &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        for(int i = 0;i < n;i++)
        {
            if(vis[i] == 0)
            {
                
                ans++;
                dfs(i,adj);
            }
        }
        return ans;

    }
};
