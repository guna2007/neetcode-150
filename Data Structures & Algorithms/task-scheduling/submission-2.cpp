class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        priority_queue<int> pq;

        for(auto &c : tasks)
        {
            freq[c - 'A']++;
        }

        for(int i = 0;i < 26;i++)
        {
            if(freq[i] > 0) pq.push(freq[i]);
        }

        int res = 0;

        while(!pq.empty())
        {
            vector<int> temp;
            for(int i = 0;i <= n;i++)
            {
                if(!pq.empty())
                {
                    int currf = pq.top();
                    pq.pop();
                    currf--;
                    temp.push_back(currf);
                }
            }

            for(int &x : temp) if(x > 0) pq.push(x);

            if(pq.empty()) res += temp.size();
            else res += n+1;
        }

        return res;
    }
};