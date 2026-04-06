class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> set(nums.begin(),nums.end());
        unordered_set<int> seen;
        int ans = 1;
        int curr = 1;
        for(int i = 0;i < n;i++)
        {
            if(seen.count(nums[i])) continue;
            int check = nums[i] + 1;
            while(set.count(check))
            {
                curr++;
                seen.insert(check);
                check++;
            }
            ans = max(ans,curr);
            curr = 1;
        }
        return ans;
    }
};