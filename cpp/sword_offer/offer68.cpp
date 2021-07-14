#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *ret = NULL;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        isContain(root, p, q);
        return ret;
    }

    bool isContain(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || ret != NULL)
            return false;

        bool left = isContain(root->left, p, q);
        bool right = isContain(root->right, p, q);
        if ((root == p || root == q) && (left || right))
            ret = root;

        return left || right || root == p || root == q;
    }
};