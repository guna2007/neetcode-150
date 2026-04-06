class Solution {
public:

    string encode(vector<string>& strs) {
        string msg = "";
        for(auto &s : strs)
        {
            int len = s.length();
            msg += to_string(len);
            msg += '#';
            msg += s;
        }
        return msg;
    }

    vector<string> decode(string msg) {
        vector<string> res;
        int i = 0;
        while(i < msg.length())
        {
            size_t pos = msg.find('#',i);  
            if (pos == string::npos) break;
            string numStr = msg.substr(i, pos - i);

            int len = stoi(numStr);

            string temp = msg.substr(pos+1,len);
            res.push_back(temp);
            i = pos + 1 + len;
        
            
        }
        return res;
    }
};
