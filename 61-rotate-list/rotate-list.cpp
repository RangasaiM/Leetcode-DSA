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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* curr=head;
        int cnt=0;
        while(curr){
            curr=curr->next;
            cnt++;
        }
        k=k%cnt;
        if(k==0) return head;
        curr=head;
        cnt=cnt-k-1;
        while(cnt--){
            curr=curr->next;
        }
        ListNode*prev=curr->next;
        ListNode*nxt=curr;
        while(nxt->next){
            nxt=nxt->next;
        }
        nxt->next=head;
        curr->next=NULL;
        return prev;
    }
};