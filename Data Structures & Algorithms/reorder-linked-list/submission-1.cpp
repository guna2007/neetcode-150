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
    void reorderList(ListNode* head) {
        stack<ListNode *> st;

        ListNode* curr = head;
        while(curr)
        {
            st.push(curr);
            curr = curr->next;
        }

        int half = st.size()/2;

        curr = head;
        for(int i = 0;i < half;i++)
        {
            ListNode* next = curr->next;
            ListNode *back = st.top();
            st.pop();

            curr->next = back;
            back->next = next;

            curr = next;

        }
        //key: i forgetten getting infinte loop
        curr->next = nullptr;
    }
};
