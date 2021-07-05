from collections import deque
from .offer07 import Solution

def tree_to_list(root):
    if root is None:
        return []

    results = []
    q = deque()
    q.append(root)
    while q:
        n = len(q)
        new_node = 0            
        while n > 0:
            n -= 1
            node = q.popleft()
            if node:
                results.append(node.val)
            else:
                results.append(None)

            if node:
                if node.left:
                    new_node += 1
                if node.right:
                    new_node += 1
                q.append(node.left)
                q.append(node.right)
        if new_node == 0:
            break
    return results

def test_empty_tree():
    preorder = []
    inorder = []
    result = Solution().buildTree(preorder, inorder)

    assert tree_to_list(result) == []

def test_normal_tree():
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]
    result = Solution().buildTree(preorder, inorder)
    
    assert tree_to_list(result) == [3, 9, 20, None, None, 15, 7]