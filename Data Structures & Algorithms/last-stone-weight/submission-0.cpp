class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        while(nums.size() > 1)
        {
            sort(nums.rbegin(),nums.rend());
            int s1 = nums[0];
            int s2 = nums[1];
            nums.erase(nums.begin(),nums.begin()+2);
            if(s1 == s2) continue;

            nums.push_back(s1-s2);
            
        } 
        if(nums.empty()) return 0;

        return nums[0];

    }
};