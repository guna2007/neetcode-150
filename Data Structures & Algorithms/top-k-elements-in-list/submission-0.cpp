class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int& x : nums) {
            freq[x]++;
        }

        // sort
        vector<pair<int, int>> vec;

        for (auto& [num, count] : freq)
            vec.push_back({count, num});

        sort(vec.begin(), vec.end(), greater<>());

        vector<int> res;
        for(int i = 0;i < k;i++)
        {
            res.push_back(vec[i].second);
        }
        return res;
    }
};