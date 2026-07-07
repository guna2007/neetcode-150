class Solution {
public:

    int Find(vector<int>& par, int n) {
        int p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool Union(vector<int>& par, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);

        if (p1 == p2)
            return false;

        par[p1] = p2;
        
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1);
        for (int i = 0; i <= n; ++i)
            par[i] = i;

        for (const auto& edge : edges) {
            if (!Union(par ,edge[0], edge[1]))
                return vector<int>{ edge[0], edge[1] };
        }
        return {};
    }


    
};