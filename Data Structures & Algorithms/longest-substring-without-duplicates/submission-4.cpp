class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0,ans = 0;
        unordered_set<char> set;

        for(int r = 0;r < n;r++)
        {
            while(set.count(s[r]))
            {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            ans = max(ans,(int)set.size());
        }
        return ans;
    }
};