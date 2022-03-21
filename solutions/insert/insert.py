fact = [1] * 101
for i in range(2, 101):
    fact[i] = i * fact[i - 1]

class Node:
    def __init__(self, val):
        self.num_of_children = 0
        self.left = None 
        self.right = None 
        self.val = val

    def num_left(self):
        if self.left is None:
            return 0
        return self.left.num_of_children + 1

    def num_right(self):
        if self.right is None:
            return 0
        return self.right.num_of_children + 1


def insert(node, k):
    node.num_of_children += 1
    if k >= node.val and node.right is None:
        node.right = Node(k)
        return
    if k < node.val and node.left is None:
        node.left = Node(k)
        return
    if k >= node.val:
        insert(node.right, k)
    else:
        insert(node.left, k)

def build(nums):
    root = Node(nums[0]) 
    for i in range(1, len(nums)):
        insert(root, nums[i])
    return root

def solve(node):
    if node is None:
        return 1
    left = solve(node.left)
    right = solve(node.right)
    res = fact[node.num_of_children]
    res //= fact[node.num_left()]
    res //= fact[node.num_right()]
    res *= left
    res *= right
    return res

def display(node):
    if node is None:
        return
    display(node.left)
    display(node.right)
    print(f"{node.val} -> {node.num_of_children}")

while True:
    n = int(input())
    if n == 0:
        break
    nums = [int(x) for x in input().split()]
    root = build(nums)
    print(solve(root))

