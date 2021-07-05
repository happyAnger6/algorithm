#include <cstdio>
#include <cstdlib>

#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in_map;
        int i = 0;
        for(auto v : inorder) {
            in_map[v] = i;
            i++;
        }

        int pre_i = 0;
        return buildNode(preorder, &pre_i, inorder, 0, inorder.size()-1, in_map);
    }

    TreeNode* buildNode(vector<int>& preorder, int *ppre_i, vector<int>& inorder, int in_left, int in_right, unordered_map<int, int> &in_map)
    {
        if(in_right < in_left)
            return NULL;

        int node_val = preorder[*ppre_i];
        *ppre_i += 1;

        struct TreeNode *node = (struct TreeNode *)malloc(sizeof(TreeNode));
        node->val = node_val;
        int mid = in_map[node_val];
        node->left = buildNode(preorder, ppre_i, inorder, in_left, mid-1, in_map);
        node->right = buildNode(preorder, ppre_i, inorder, mid + 1, in_right, in_map);
        return node;
    }
};