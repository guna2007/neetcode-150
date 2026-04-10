class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at tail
    Node* inserttail(int key, int val) {
        Node* node = new Node(key, val);

        if (!head) {
            head = tail = node;
            return node;
        }

        tail->next = node;
        node->prev = tail;
        tail = node;
        return node;
    }

    // Remove from head
    void remhead() {
        if (!head) return;

        Node* temp = head;
        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    // Move given node to tail
    void shiftnode(Node* node) {
        if (!node || node == tail) return;

        // detach
        if (node == head) {
            head = node->next;
            if (head) head->prev = nullptr;
        } else {
            node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;
        }

        // attach at tail
        node->next = nullptr;
        node->prev = tail;

        if (tail)
            tail->next = node;

        tail = node;
    }
};


class LRUCache {
public:

    unordered_map<int, Node*> mp;
    DLL dll;
    int c;

    LRUCache(int cap) {
        c = cap;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            dll.shiftnode(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // key exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            dll.shiftnode(node);
            return;
        }

        // new key
        if (mp.size() == c) {
            int oldKey = dll.head->key;
            mp.erase(oldKey);
            dll.remhead();
        }

        Node* node = dll.inserttail(key, value);
        mp[key] = node;
    }
};