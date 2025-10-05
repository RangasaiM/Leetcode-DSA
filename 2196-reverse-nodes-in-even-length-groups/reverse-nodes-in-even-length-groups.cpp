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

    ListNode* reverse(ListNode* head,int k,ListNode* nxt){
        ListNode* curr=head;
        ListNode* prev=nxt;
        while(k && curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            k--;
        }
        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(!head) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*ans= dummy;
        ListNode* curr=head;
        int k=1;
        while(curr){
            int n=k;
            ListNode*currHead=curr;
            ListNode* prev=curr;
            while(n && curr){
                prev=curr;
                curr=curr->next;
                n--;
            }
            if((k-n)%2!=0){
                dummy=prev;
            }
            else{
                dummy->next=reverse(currHead,k,curr);
                dummy=currHead;
            }
            k++;
        }
        return ans->next;
    }
};