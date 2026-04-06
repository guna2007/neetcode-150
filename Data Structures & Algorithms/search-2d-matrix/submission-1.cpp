class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {

        int m = mat.size();
        int n = mat[0].size();

        int l = 0, h = m*n - 1;

        while (l <= h) {

            int mid = l + (h - l) / 2;

            int val = mat[mid / n][mid % n];

            if (val == t) return true;
            else if (val > t) h = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};