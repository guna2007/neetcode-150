class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++)
        {
            mp[nums[i]] = i;
        }

        for(int i = 0;i < n;i++)
        {
            int t = target - nums[i];
            if(mp.find(t) != mp.end() && mp[t] != i)
            {
                return {i,mp[t]};
            }
        }
        return {-1,-1};
    }
};
