class Solution {
public:

    void helper(int op,int cl,string& curr,vector<string>& res,int n)
    {
        //bc
        if(op == n && cl == n)
        {
            res.push_back(curr);
            return;
        }

        //pick (
        if(op < n)
        {
            curr += '(';

            helper(op + 1,cl,curr,res,n);

            curr.pop_back();
        }

        //pick )
        if(op > cl)
        {
            curr += ')';

            helper(op,cl + 1,curr,res,n);

            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        //logic is just to use helper func
        //2 vars for tracking open,close bracks
        //inc them if putting into curr
        //push into res if op , cl are n
        //do not put ) if op <= cl
        //use pick,not pick like recursion but ( or )

        vector<string> res;
        string curr = "";

        helper(0,0,curr,res,n);

        return res;
    }
};