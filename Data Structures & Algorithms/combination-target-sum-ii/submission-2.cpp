class Solution {
public:

    vector<vector<int>> res;

    void helper(int idx,
                vector<int>& uniqueNums,
                unordered_map<int,int>& freq,
                vector<int>& temp,
                int target)
    {
        // valid combination
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        // invalid
        if(target < 0 || idx == uniqueNums.size())
            return;

        int num = uniqueNums[idx];

        // PICK current number
        if(freq[num] > 0)
        {
            temp.push_back(num);

            freq[num]--;

            // stay at same idx
            // because more copies may exist
            helper(idx,
                   uniqueNums,
                   freq,
                   temp,
                   target - num);

            freq[num]++;
            temp.pop_back();
        }

        // NOT PICK current number
        helper(idx + 1,
               uniqueNums,
               freq,
               temp,
               target);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums,
                                        int target)
    {
        unordered_map<int,int> freq;

        vector<int> uniqueNums;

        // build frequency map
        for(int num : nums)
        {
            if(freq[num] == 0)
            {
                uniqueNums.push_back(num);
            }

            freq[num]++;
        }

        vector<int> temp;

        helper(0,
               uniqueNums,
               freq,
               temp,
               target);

        return res;
    }
};