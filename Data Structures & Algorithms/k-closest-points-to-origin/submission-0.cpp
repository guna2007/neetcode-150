class Solution {
public:

    pair<double,vector<int>> calc(vector<int> &p)
    {
        int d = (p[0] * p[0]) + (p[1]*p[1]);
        return {d,p};
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>> pq;

        for(auto x : points)
        {
            pq.push(calc(x));
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