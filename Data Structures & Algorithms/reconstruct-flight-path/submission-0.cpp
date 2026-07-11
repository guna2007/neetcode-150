class Solution {
public:

    int n;

    bool dfs(const string& src, vector<string>& res,unordered_map<string, vector<string>>& adj) {
        if (res.size() == n+1) {
            return true;
        }

        if (adj.find(src) == adj.end()) {
            return false;
        }

        vector<string> temp = adj[src];
        for (int i = 0; i < temp.size(); ++i) {
            string v = temp[i];
            adj[src].erase(adj[src].begin() + i);
            res.push_back(v);
            if (dfs(v, res, adj)) return true;
            adj[src].insert(adj[src].begin() + i, v);
            res.pop_back();
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        unordered_map<string, vector<string>> adj;
        sort(tickets.begin(), tickets.end());

        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res = {"JFK"};
        dfs("JFK", res, adj);
        return res;
    }



};