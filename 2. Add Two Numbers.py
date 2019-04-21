# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        head = ListNode(0)
        node = head
        while l1 and l2:
            value = (l1.val + l2.val + carry) % 10
            carry = (l1.val + l2.val + carry) // 10
            l1.val = value
            node.next = l1
            node = node.next
            l1 = l1.next
            l2 = l2.next

        while l1:
            value = (l1.val + carry) % 10
            carry = (l1.val + carry) // 10
            l1.val = value
            node.next = l1
            node = node.next
            l1 = l1.next

        while l2:
            value = (l2.val + carry) % 10
            carry = (l2.val + carry) // 10
            l2.val = value
            node.next = l2
            node = node.next
            l2 = l2.next

        if carry:
            node.next = ListNode(carry)

        return head.next
            
            
        
        
        