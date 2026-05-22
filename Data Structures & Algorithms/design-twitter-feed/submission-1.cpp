class Twitter {
public:
    
    int time = 0;

    unordered_map<int, set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<pair<int,int>> temp;

        followers[userId].insert(userId);

        for(auto &id : followers[userId])
        {
            for(auto &tweet : tweets[id])
            {
                temp.push_back(tweet);
            }
        }

        sort(temp.rbegin(), temp.rend());

        vector<int> ans;

        for(int i = 0; i < min(10, (int)temp.size()); i++)
        {
            ans.push_back(temp[i].second);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};