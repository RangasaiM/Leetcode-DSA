# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(not head):
            return head
        dummy=ListNode(-1)
        dummy.next=head
        temp=dummy
        curr=head
        
        while(curr):
            if(curr and curr.next and curr.val==curr.next.val):
                while(curr and curr.next and curr.val==curr.next.val):
                    curr=curr.next
                dummy.next=curr.next
            else:
                dummy=dummy.next
            curr=curr.next
        return temp.next
