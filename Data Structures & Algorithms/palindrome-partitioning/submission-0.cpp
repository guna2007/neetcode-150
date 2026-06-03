class Solution {
public:

    bool ispal(int i,int j,string& s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    void helper(int i,string& s,vector<string>& temp,vector<vector<string>>& res)
    {
        //bc
        if(i == s.length())
        {
            res.push_back(temp);
            return;
        }

        //j looping iterator
        for(int j = i; j < s.length(); j++)
        {
            //pick
            if(ispal(i,j,s))
            {
                temp.push_back(s.substr(i,j - i + 1));

                helper(j + 1,s,temp,res);

                temp.pop_back();
            }

            //ignore
            else
            {
                continue;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        //here logic is to use helper with i,j where i is start and j is the looping iterator
        //check if s[i..j] is pal if yes push into temp
        //also dont push, ignore it by updating start vec
        //if not pal only case is to ingnore so update
        //bc is to push into res if start reaches last

        //return res

        vector<vector<string>> res;
        vector<string> temp;

        helper(0,s,temp,res);

        return res;
    }
};