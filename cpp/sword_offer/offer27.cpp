#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        mirrorTree(root->left);
        mirrorTree(root->right);

        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        return root;
    }
};