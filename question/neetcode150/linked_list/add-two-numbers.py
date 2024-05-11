from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0)
        node = head
        carry = 0
        while l1 or l2:
            cur = 0
            if l1:
                cur += l1.val
            if l2:
                cur += l2.val
            cur = cur + carry
            cur, carry = cur%10, cur//10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

            node.next = ListNode(cur)
            node = node.next

        if carry:
            node.next = ListNode(1)

        return head.next