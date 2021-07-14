#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        int val = root->val;
        int pval = p->val;
        int qval = q->val;

        if (val == pval || val == qval)
            return root;
        
        if (((val - pval) ^ (val - qval)) < 0)
            return root;

        if (pval < val)
            return lowestCommonAncestor(root->left, p, q);

        return lowestCommonAncestor(root->right, p, q);
    }
};