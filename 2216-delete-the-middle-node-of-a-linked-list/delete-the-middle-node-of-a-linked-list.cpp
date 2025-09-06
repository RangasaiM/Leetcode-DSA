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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        
        
        auto hare=head;
        ListNode* tourtaise=new ListNode(-1);
        tourtaise->next=head;
        
        while(hare && hare->next){
            hare=hare->next->next;
            tourtaise=tourtaise->next;
        }
        
        tourtaise->next=tourtaise->next->next;
        
        return head;
    }
};