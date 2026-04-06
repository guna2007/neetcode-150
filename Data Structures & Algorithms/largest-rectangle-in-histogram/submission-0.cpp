class Solution {
public:

    vector<int> pse(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for(int i = 0;i< n;i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> nse(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if(st.empty()) res[i] = n;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps = pse(nums);
        vector<int> ns = nse(nums);
        int ans = 0;

        for(int i = 0;i < n;i++)
        {
            int area = nums[i] * (ns[i]-ps[i]-1);
            ans = max(ans,area);
        }

        // for(int x : ns)
        // {
        //     cout<<x<<" ";
        // }
        return ans;
    }
};