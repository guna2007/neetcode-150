class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *c1 = l1;
        ListNode *c2 = l2;
        ListNode *prev = NULL;

        int carry = 0;

        while(c1 && c2)
        {
            int val = c1->val + c2->val + carry;
            carry = val / 10;
            c1->val = val % 10;

            prev = c1;
            c1 = c1->next;
            c2 = c2->next;
        }

        while(c1)
        {
            int val = c1->val + carry;
            carry = val / 10;
            c1->val = val % 10;

            prev = c1;
            c1 = c1->next;
        }

        while(c2)
        {
            int val = c2->val + carry;
            carry = val / 10;

            prev->next = new ListNode(val % 10);
            prev = prev->next;

            c2 = c2->next;
        }

        if(carry)
        {
            prev->next = new ListNode(carry);
        }

        return l1;
    }
};