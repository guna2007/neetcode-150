class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int,vector<int>> pq(nums.begin(),nums.end());

        while(pq.size() > 1)
        {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            if(s1 == s2) continue;
            pq.push(s1-s2);
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};
