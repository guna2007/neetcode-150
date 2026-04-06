class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        int need[26] = {0};
        int window[26] = {0};

        for (char c : s1)
            need[c - 'a']++;

        int l = 0;

        for (int r = 0; r < n2; r++) {
            int idx = s2[r] - 'a';
            window[idx]++;

            while (window[idx] > need[idx]) {
                window[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == n1)
                return true;
        }

        return false;
    }
};