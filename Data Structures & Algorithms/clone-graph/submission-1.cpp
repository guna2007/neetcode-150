/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> mp;

    Node* helper(Node*  node)
    {
        if(mp.find(node->val) != mp.end())
        {
            return mp[node->val];
        }

        Node* copy = new Node(node->val);
        mp[node->val] = copy;

        for(Node * nei : node->neighbors)
        {
            copy->neighbors.push_back(helper(nei));
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        return helper(node);        
    }
};
