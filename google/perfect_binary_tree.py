"""
   7
 3   6
1 2 4 5

Write a function solution(h, q) - where h is the height of the perfect tree of converters and q is a list of positive integers representing different flux converters
- which returns a list of integers p where each element in p is the label of the converter that sits on top of the respective converter in q, or -1 if there is no
such converter.  For example, solution(3, [1, 4, 7]) would return the converters above the converters at indexes 1, 4, and 7 in a perfect binary tree of height 3,
which is [3, 6, -1].

The domain of the integer h is 1 <= h <= 30, where h = 1 represents a perfect binary tree containing only the root, h = 2 represents a perfect binary tree with
the root and two leaf nodes, h = 3 represents a perfect binary tree with the root, two internal nodes and four leaf nodes (like the example above), and so forth.
The lists q and p contain at least one but no more than 10000 distinct integers, all of which will be between 1 and 2^h-1, inclusive.

-- Python cases --
Input:
solution.solution(3, [7, 3, 5, 1])
Output:
    -1,7,6,3

Input:
solution.solution(5, [19, 14, 28])
Output:
    21,15,29
"""

from __future__ import print_function


def solution(h, q):
    root_num = 2 ** h - 1
    root = Node(root_num).post_order_insert(h, list(range(root_num+1)))

    for i in q:
        if root.data == i:
            print(-1, end='')
        else:
            get_parent(root, i)

        if i != q[-1]:
            print(",", end='')


# Get Parent Node Data
def get_parent(node, data):
    if node.left:
        get_parent(node.left, data)
    if node.right:
        get_parent(node.right, data)

    if node.left is None:
        return

    if node.left.data == data:
        print(node.data, end='')
    elif node.right.data == data:
        print(node.data, end='')


class Node:
    def __init__(self, data=None):
        self.left = None
        self.right = None
        self.data = data

    # Insert Node in post-order traversal
    def post_order_insert(self, height, nums):
        if height == 1:
            return Node(nums.pop())
        node = Node()
        node.data = nums.pop()
        node.right = self.post_order_insert(height - 1, nums)
        node.left = self.post_order_insert(height - 1, nums)
        return node


solution(3, [7, 3, 5, 1])
print()
solution(5, [19, 14, 28])