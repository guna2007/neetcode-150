class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);

        pre[0] = nums[0], suf[n-1] = nums[n-1];

        for(int i = 1;i < n;i++)
        {
            pre[i] = pre[i-1] * nums[i];
        }

        for(int i = n-2;i >= 0;i--)
        {
            suf[i] = suf[i+1] * nums[i];
        }

        vector<int> res(n);

        for(int i = 0;i < n;i++)
        {
            int ans = ((i-1 >= 0)? pre[i-1] : 1) * ((i+1 < n)? suf[i+1] : 1);
            res[i] =  ans;
        }

        return res;

    }
};