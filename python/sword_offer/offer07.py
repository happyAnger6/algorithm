class TreeNode:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        in_map = {}
        for i, num in enumerate(inorder):
            in_map[num] = i


        pre_i = 0; 
        def build_root(preorder, inorder, in_left, in_right):
            nonlocal pre_i, in_map
            if in_right < in_left:
                return None

            root_val = preorder[pre_i]
            root = TreeNode(root_val)
            pre_i += 1
            mid = in_map[root_val]
            root.left = build_root(preorder, inorder, in_left, mid-1)
            root.right = build_root(preorder, inorder, mid+1, in_right)
            return root

        return build_root(preorder, inorder, 0, len(inorder)-1)
