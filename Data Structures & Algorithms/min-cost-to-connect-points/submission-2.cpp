class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
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