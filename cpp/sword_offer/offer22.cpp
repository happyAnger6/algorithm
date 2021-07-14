#include <cstdint>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL)
            return head;

        struct ListNode *last = head, *first = head;
        int tmp = k;
        while (tmp > 0 && last) {
            last = last->next;
            tmp -= 1;
        }

        if (tmp > 0)
            return NULL;

        while (last) {
            last = last->next;
            first = first->next;
        } 

        return first;
    }
};