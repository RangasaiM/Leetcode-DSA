
class Node{
public:
    int data;
    Node* next;
    Node(int v){
        this->data=v;
        this->next=nullptr;
    }
};


class MyLinkedList {
public:
    Node* head;
    int length;
    MyLinkedList() {
        head=NULL;
        length=0;
    }
    
    int get(int index) {
        if(index<0 || index>=length) return -1;
        Node *temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node *temp=new Node(val);
        temp->next=head;
        head=temp;
        length++;
    }
    
    void addAtTail(int val) {
        Node *newNode=new Node(val);
        if(!head){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>length) return;
        Node* temp=head;
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==length){
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        for(int i=0;i<index-1;i++) temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=length || head==NULL) return;
        Node* temp=head;
        if(index==0){
            head=head->next;
            delete temp;
            length--;
            return;
        }
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node *stemp=temp->next;
        temp->next=temp->next->next;
        delete stemp;
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */