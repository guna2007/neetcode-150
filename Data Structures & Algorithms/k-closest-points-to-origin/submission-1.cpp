class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;

        for(auto &p : points)
        {
            int dist = (p[0] * p[0]) + (p[1] * p[1]);
            pq.push({dist, p});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while(!pq.empty())
        {
            auto [d,temp]= pq.top();pq.pop();
            res.push_back(temp);
        }
        return res;
    }
};