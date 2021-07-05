#include <cstdlib>

#include <vector>

using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> results;

        if (head == NULL)
            return {};
        
        printNode(head, results);
        return results;
    }

    void printNode(ListNode* head, vector<int> &results)
    {
        if (head->next != NULL) {
            printNode(head->next, results);
        }

        results.push_back(head->val);
    }
};