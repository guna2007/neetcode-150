class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            if (mp[x] != 0)
                return true;
            mp[x]++;
        }
        return false;
    }
};