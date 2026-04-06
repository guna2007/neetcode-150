class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int& x : nums) {
            freq[x]++;
        }

        //use heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;

        for(auto &[num,cnt]: freq)
        {
            minheap.push({cnt,num});
            if(minheap.size() > k)
            {
                minheap.pop();
            }
        }

        vector<int> res;
        while (!minheap.empty()) {
            res.push_back(minheap.top().second);  // take the number
            minheap.pop();
        }

        return res;
    }
};