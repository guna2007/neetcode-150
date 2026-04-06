class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = 0,curr = 0;

        for(int r = l;r < n;r++)
        {
            if(nums[r] - nums[l] < 0)
            {
                l = r;
                continue;
            }
            ans = max(ans,nums[r]-nums[l]);
        }

        return ans;
    }
};