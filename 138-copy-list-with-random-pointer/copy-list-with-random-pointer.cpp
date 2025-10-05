/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void insertCopy(Node* head){
        Node* curr=head;
        while(curr){
            Node* temp=curr->next;
            Node* newNode = new Node(curr->val);
            newNode->next=temp;
            curr->next=newNode;
            curr=temp;
        }
    }

    void makeRandom(Node* head){
        Node* temp=head;
        Node* newNode=temp->next;
        while(temp){
            newNode=temp->next;
            if(temp && temp->random)
            newNode->random=temp->random->next;
            else
            newNode->random=NULL;
            temp=temp->next->next;
        }
    }

    Node* removeLinks(Node* head){
        Node* dummy=new Node(-1);
        Node* ans=dummy;
        Node* temp=head;
        while(temp){
            dummy->next=temp->next ;
            dummy=dummy->next;

            temp->next=temp->next->next;
            temp=temp->next;
        }
        return ans->next;

    }

    Node* copyRandomList(Node* head) {
        if(!head) return head;
        insertCopy(head);
        makeRandom(head);
        return removeLinks(head);
    }
};