class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0],ans = 0;

        for(auto x : nums)
        {
            ans = max(ans,x - mini);
            mini = min(mini,x);
        }

        return ans;
        
    }
};
