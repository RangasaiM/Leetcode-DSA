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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* ans=dummy;
        ListNode* curr=head;
        while(curr){
            if(curr && curr->next && curr->val==curr->next->val){
                while(curr && curr->next && curr->val==curr->next->val){
                    curr=curr->next;
                }
                dummy->next=curr;
                dummy=dummy->next;
            }
            else{
                dummy=dummy->next;
            }
            curr=curr->next;
        }
        return ans->next;
    }
};