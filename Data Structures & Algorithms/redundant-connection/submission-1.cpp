class Solution {
public:

    vector<int> par;

   int find(int x)
    {
        if (par[x] == x)
            return x;

        par[x] = find(par[x]);

        return par[x];
    }

    bool unionof(int n1,int n2)
    {
        int par1 = find(n1);
        int par2 = find(n2);

        if(par1 == par2) return true;

        par[par2] = par1;
        return false;
    }



    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);

        //par
        for(int i = 0;i <= n;i++)
        {
            par[i] = i;
        }

        for(int i = 0;i < n;i++)
        {
            if(unionof(edges[i][0],edges[i][1]))
            {
                return edges[i];
            }
        }
        return {};
    }
};
