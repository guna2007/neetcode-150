

//optimal: single pass
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;

        Node* cur = head;
        while (cur != nullptr) {
            if (mp.find(cur) == mp.end()) {
                mp[cur] = new Node(0);
            }
            mp[cur]->val = cur->val;
            if (mp.find(cur->next) == mp.end()) {
                mp[cur->next] = new Node(0);
            }
            mp[cur]->next = mp[cur->next];
            if (mp.find(cur->random) == mp.end()) {
                mp[cur->random] = new Node(0);
            }
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};