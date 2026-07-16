class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // graph -> {next, cost}
        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        // min cost to reach each node
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // {node, cost}
        queue<pair<int,int>> q;
        q.push({src, 0});

        int level = 0;

        // each level = one flight used
        while(!q.empty() && level <= k)
        {
            int size = q.size();

            while(size--)
            {
                auto [node, cost] = q.front();
                q.pop();

                // try all neighbours
                for(auto &[next, price] : adj[node])
                {
                    int newCost = cost + price;

                    // found cheaper path
                    if(newCost < dist[next])
                    {
                        dist[next] = newCost;
                        q.push({next, newCost});
                    }
                }
            }

            level++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};