class Solution {
   public:
    vector<int> dist;
    int INF = 1e9;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min heap

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dijsktras using dist arr
        //  and getting max of it

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adj[u].push_back({v, time});
        }

        dist.resize(n + 1, INF);

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto [nei, wt] : adj[node]) {
                if (currDist + wt < dist[nei]) {
                    dist[nei] = currDist + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());

        return ans == INF ? -1 : ans;
        // return ans;
    }
};