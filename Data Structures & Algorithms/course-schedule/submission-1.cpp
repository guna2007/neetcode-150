class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        queue<int> q;
        for(auto &v : graph)
        {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        for(int i = 0;i < n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int sum = 0;
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            sum++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if(sum == n) return true;
        return false;


    }
};
