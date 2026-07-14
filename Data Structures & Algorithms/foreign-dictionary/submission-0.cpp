class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        // mark all characters that are present
        for (auto word : words)
        {
            for (auto ch : word)
                present[ch - 'a'] = 1;
        }

        // compare every adjacent pair
        for (int i = 0; i < words.size() - 1; i++)
        {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            bool found = false;

            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].insert(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            // invalid case
            if (!found && s1.size() > s2.size())
                return "";
        }

        // calculate indegree
        for (int i = 0; i < 26; i++)
        {
            for (auto nei : adj[i])
                indegree[nei]++;
        }

        queue<int> q;

        for (int i = 0; i < 26; i++)
        {
            if (present[i] && indegree[i] == 0)
                q.push(i);
        }

        string ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (auto nei : adj[node])
            {
                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (present[i])
                cnt++;
        }

        if (ans.size() != cnt)
            return "";

        return ans;
    }
};