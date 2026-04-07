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
    ListNode* removeNthFromEnd(ListNode* head, int t) {
        int n = 0;
        ListNode* curr = head;
        while(curr)
        {
            n++;
            curr = curr->next;
        }
        int k = n - t;

        ListNode* prev = nullptr;
        curr = head;
        while(k--)
        {
            prev = curr;
            curr = curr->next;
        }
        if(prev == nullptr)
        {
            ListNode *next = head->next;
            delete head;
            return next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
    }
};
