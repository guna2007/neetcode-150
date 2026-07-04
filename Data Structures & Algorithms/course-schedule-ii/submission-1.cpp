class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<int> res;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;

        for(auto &v : graph)
        {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        for(int i = 0;i < n;i++)
        {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            res.push_back(curr);

            for(int nei : adj[curr])
            {
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        if(res.size() != n) return {};

        return res;
    }
};
