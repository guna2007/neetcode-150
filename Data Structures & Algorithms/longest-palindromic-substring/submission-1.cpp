class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int len = 0, idx = 0;

        for (int i = 0; i < n; i++) 
        {
            // odds
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) 
            {
                if (r - l + 1 > len) 
                {
                    idx = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }

            // evens 
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) 
            {
                if (r - l + 1 > len) 
                {
                    idx = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(idx, len);
    }
};