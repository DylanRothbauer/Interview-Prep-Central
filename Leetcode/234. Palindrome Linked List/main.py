# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        List = []
        while head:
            List.append(head.val)
            head = head.next
        left = 0
        right = len(List) - 1

        while left < right and List[left] == List[right]:
            left+=1
            right-=1
        return left >= right