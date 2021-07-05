 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        ListNode *ins = nullptr;
        while (l1 && l2) {
            if (l1->val <= l2->val)
            {
                ins = l1;
                l1 = l1->next;
            }
            else
            {
                ins = l2;
                l2 = l2->next;
            }
            tail->next = ins;
            tail = ins;
        }

        if (l1)
            tail->next = l1;

        if (l2)
            tail->next = l2;

        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
    }
};