 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return cmp(root, root);
    }

    bool cmp(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return true;

        if (t1 && t2)
            return t1->val == t2->val && cmp(t1->left, t2->right) &&
                cmp(t1->right, t2->left);

        return false;
    }
};