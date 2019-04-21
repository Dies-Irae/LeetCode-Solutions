# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        array = []
        while(head != None):
            array.append(head.val)
            head = head.next
        del array[-n]
        #print(array)
        newhead = ListNode(0)
        
        p = newhead
        for elem in array:
            p.next = ListNode(elem)
            p = p.next
        return newhead.next