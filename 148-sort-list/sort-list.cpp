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
    ListNode* merge(ListNode* left,ListNode* right){
    ListNode* dummy=new ListNode(0);
    ListNode*current=dummy;
    
    while(left && right){
        if(left->val<right->val){
            current->next=new ListNode(left->val);
            current=current->next;
            left=left->next;
        }
        else{
            current->next=new ListNode(right->val);
            current=current->next;
            right=right->next;
        }
    }
    if(left) current->next=left;
    if(right) current->next=right;
    return dummy->next;
}

    ListNode* findMid(ListNode* head){
        if(!head) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* mid=findMid(head);
        ListNode*right=mid->next;
        mid->next=NULL;
        ListNode*left = sortList(head);
        ListNode* rightSorted = sortList(right);
        
        return merge(left,rightSorted);
    }
};