class LRUCache {
public:
    int cap;
    list<pair<int,int>> dll; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;

        dll.erase(it);
        dll.push_back({key, val});
        mp[key] = prev(dll.end());

        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        else if(dll.size() == cap) {
            auto front = dll.front();
            mp.erase(front.first);
            dll.pop_front();
        }

        dll.push_back({key, value});
        mp[key] = prev(dll.end());
    }
};