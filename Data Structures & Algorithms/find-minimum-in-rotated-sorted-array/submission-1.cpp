class Solution {
public:
    int findMin(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r= n-1;

        int ans = arr[0];
        while(l <= r)
        {
            if(arr[l] <= arr[r]) 
            {
                ans = min(ans,arr[l]);
                break;
            }
            int mid = l + (r-l)/2;
            ans = min(ans,arr[mid]);

            if(arr[l] <= arr[mid])
            {
                l = mid+1;
            }
            else r = mid-1;

        }

        return ans;
    }
};
