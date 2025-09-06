/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        auto temp=dummy;
        
        for(int i=0;i<left-1;i++){
            temp=temp->next;
        }
        
        auto front=temp->next;
        auto nxt=temp->next;
        ListNode* back=NULL;
        
        for(int i=left;i<=right;i++){
            nxt=nxt->next;
            front->next=back;
            back=front;
            front=nxt;
        }
        temp->next->next=front;
        temp->next=back;
    
        return dummy->next;
    }
};