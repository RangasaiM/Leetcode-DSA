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

    ListNode* findK(ListNode* head,int k){
        ListNode* kth=head;
        while(k>1 && kth!=NULL){
            kth=kth->next;
            k--;
        }
        if(kth==NULL) return head;
        return kth;
    }

    void reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp!=NULL){
            ListNode* Kth = findK(temp,k);
            if(Kth == temp){
                if(prev){
                    prev->next=Kth;
                }
                break;
            }
            else{
                ListNode* nextNode = Kth->next;
                Kth->next = NULL;
                reverse(temp);
                if(temp==head) head=Kth;
                else{
                    prev->next=Kth;
                }
                prev=temp;
                temp = nextNode;
            }

        }
        return head;
    }
};
