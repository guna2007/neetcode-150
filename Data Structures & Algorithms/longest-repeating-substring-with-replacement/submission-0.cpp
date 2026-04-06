class Solution {
public:

    int maxf(unordered_map<char,int> &freq)
    {
        int ans = 0;
        for(auto &[c,x] : freq)
        {
            ans = max(ans,x);
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        int n = s.length();

        int l = 0,ans = 0;
        unordered_map<char,int> freq;

        for(int r = 0;r < n;r++)
        {
            freq[s[r]]++;
            
            
            int maxi = maxf(freq);
            while(r-l+1 - maxi > k)
            {
                freq[s[l]]--;
                l++;
                maxi = maxf(freq);
            }

            ans = max(ans,r-l+1);
        }

        return ans;
    }
};