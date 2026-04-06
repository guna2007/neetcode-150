class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 > n2) return false;

        int freq1[26] = {0};
        for (char& x : s1) {
            freq1[x - 'a']++;
        }

        int l = 0;
        int freq2[26] = {0};
        for (int i = 0; i < n1; i++) {
            freq2[s2[i] - 'a']++;
        }

        bool equal = true;
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                equal = false;
                break;
            }
        }
        if (equal) return true;

        for (int r = n1; r < n2; r++) {
            freq2[s2[l] - 'a']--;
            l++;
            freq2[s2[r] - 'a']++;

            equal = true;
            for (int i = 0; i < 26; i++) {
                if (freq1[i] != freq2[i]) {
                    equal = false;
                    break;
                }
            }
            if (equal) return true;
        }
        return false;
    }
};