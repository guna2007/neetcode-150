class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<int> ans(n,0);
        for(int r = n- 1;r >= 0;r--)
        {
            while(!st.empty() && st.top().first <= nums[r])
            {
                st.pop();
            }
            if(st.empty()) ans[r] = 0;
            else ans[r] = st.top().second - r;
            st.push({nums[r],r});
        }

        return ans;
    }
};