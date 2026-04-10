/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:


    static bool comp(ListNode* const& n1, ListNode* const& n2) {
        // Return true if n1's priority is lower than n2's (for a min-heap)
        return n1->val > n2->val;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, decltype(&comp)> minheap(comp);        
        ListNode dummy(0);
        ListNode* curr = &dummy;

        for(int i = 0; i < k; i++)
        {
            if(lists[i] != NULL)
                minheap.push(lists[i]);
        }
        
            
        while(!minheap.empty())
        {
            ListNode* temp = minheap.top(); 
            minheap.pop();
            curr->next = temp;
            if(temp->next != NULL)
                minheap.push(temp->next);
            curr = curr->next;
        }

        return dummy.next;
    }
};
