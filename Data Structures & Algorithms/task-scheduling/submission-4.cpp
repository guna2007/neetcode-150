class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &c : tasks)
        {
            freq[c-'A']++;
        }

        sort(freq.rbegin(),freq.rend());
        

        int idle = (freq[0] - 1) * n;

        for(int i = 1;i < 26;i++)
        {
            idle -= min(freq[0] - 1,freq[i]); // upper bound is no.of gaps 
        }

        idle = max(0, idle);

        if(idle == 0) return tasks.size();
        return tasks.size() + idle;

    }
};
