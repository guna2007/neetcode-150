class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++) 
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) 
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int res = 0;
        unordered_set<int> visit;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (visit.size() < n) 
        {
            auto curr = pq.top();
            pq.pop();
            int cost = curr.first;
            int i = curr.second;
            if (visit.count(i)) {
                continue;
            }
            res += cost;
            visit.insert(i);
            for(int nei = 0; nei < n; nei++)
            {
                if(visit.count(nei))
                    continue;

                int dist =
                    abs(points[i][0] - points[nei][0]) +
                    abs(points[i][1] - points[nei][1]);

                pq.push({dist, nei});
            }
        }
        return res;
    }
};