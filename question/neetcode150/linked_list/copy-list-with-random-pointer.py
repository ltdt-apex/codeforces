from typing import Optional

class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        d = {None:None}

        cur = head 
        while cur:
            d[cur] = Node(cur.val)
            cur = cur.next

        cur = head
        while cur:
            d[cur].next = d[cur.next]
            d[cur].random = d[cur.random]
            cur = cur.next

        return d[head]