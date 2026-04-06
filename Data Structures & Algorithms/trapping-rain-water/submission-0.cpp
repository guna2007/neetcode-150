class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        //tc n, sc n
        vector<int> pre(n,0), suf(n,0);

        //fill those arrs
        for(int i = 1;i < n;i++)
        {
            pre[i] = max(pre[i-1],h[i-1]);
        }
        for(int i = n-2;i >= 0;i--)
        {
            suf[i] = max(suf[i+1],h[i+1]);
        }

        //now find ans
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int curr = min(pre[i],suf[i]) - h[i];
            if(curr < 0) curr = 0;
            ans += curr;
        }
        return ans;
    }
};