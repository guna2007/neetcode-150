class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 > n2) return false;
        unordered_map<char, int> freq1;
        for (char& x : s1) {
            freq1[x]++;
        }

        int l = 0;
        unordered_map<char, int> freq2;
        for (int i = 0; i < n1; i++) {
            freq2[s2[i]]++;
        }

        if (freq1 == freq2) {
            return true;
        }

        for (int r = n1; r < n2; r++) {
            freq2[s2[l]]--;
            if (freq2[s2[l]] == 0)
                freq2.erase(s2[l]);
            l++;
            freq2[s2[r]]++;
            if (freq1 == freq2) {
                return true;
            }
        }
        return false;
    }
};
