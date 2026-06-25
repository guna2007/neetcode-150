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

    Node* helper(Node* node)
    {
        if(node == NULL) return NULL;
        int v = node->val;

        if(mp.find(v) != mp.end()) return mp[v];


        Node* newnode = new Node(v);
        mp[v] = newnode;

        for(Node* nei : node->neighbors)
        {
            newnode->neighbors.push_back(helper(nei));
        }

        return newnode;


    }

    Node* cloneGraph(Node* node) {


        return helper(node);

        
    }
};
