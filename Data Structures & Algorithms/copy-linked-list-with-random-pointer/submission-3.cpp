class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node*, Node*> mp;
        mp.reserve(1000); // 🔥 reduces rehashing (important)

        Node* curr = head;

        // 🔥 First pass: create all nodes
        while(curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        // 🔥 Second pass: assign next + random
        while(curr) {
            Node* copy = mp[curr];

            copy->next = curr->next ? mp[curr->next] : nullptr;

            if(curr->random)
                copy->random = mp[curr->random];
            else
                copy->random = nullptr;

            curr = curr->next;
        }

        return mp[head];
    }
};