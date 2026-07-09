class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        
        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                string word = q.front();
                q.pop();

                if(word == endWord)
                    return steps;

                for(int i = 0; i < word.size(); i++)
                {
                    char curr = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;

                        if(st.find(word) != st.end())
                        {
                            q.push(word);
                            st.erase(word);
                        }
                    }

                    word[i] = curr;
                }
            }

            steps++;
        }

        return 0;
        
    }
};
