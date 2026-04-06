class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &s : tokens)
        {
            if(all_of(s.begin(), s.end(), ::isdigit) || 
               (s.size() > 1 && s[0] == '-' && all_of(s.begin()+1, s.end(), ::isdigit)))
            {
                st.push(stoi(s));
            }
            else if(s == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a+b);
            }
            else if(s == "-")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a-b);
            }
            else if(s == "*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a*b);
            }
            else if(s == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a/b);
            }
        }

        return st.top();
    }

};