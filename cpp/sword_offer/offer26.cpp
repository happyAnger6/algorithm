#include <cstdio>
#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL)
            return true;
        
        if (A != NULL && B != NULL) {
            if (A->val == B->val && isSubStructure(A->left, B->left) 
                    && isSubStructure(A->right, B->right))
                    return true;
            
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);

        }

        return false;
    }
};