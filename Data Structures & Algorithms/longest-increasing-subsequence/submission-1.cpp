class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;

        for(int x : nums)
        {
            auto it = lower_bound(arr.begin(), arr.end(), x);

            if(it == arr.end()) arr.push_back(x);
            else *it = x;
        }

        return arr.size();
    }
};
