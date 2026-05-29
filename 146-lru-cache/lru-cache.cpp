class Node {
public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};


class LRUCache {
public:

    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    LRUCache(int capacity){
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        this->head->next=tail;
        this->tail->prev=head;
    }

    void deleteNode(Node* d){
        d->prev->next=d->next;
        d->next->prev=d->prev;
    }

    void insertAfterHead(Node* d){
        d->next=head->next;
        d->prev=head;
        d->next->prev=d;
        head->next=d;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            insertAfterHead(mp[key]);
            return mp[key]->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            insertAfterHead(mp[key]);
            mp[key]->val=value;
        }
        else{
            if(mp.size()==capacity){
                Node* temp=tail->prev;
                mp.erase(temp->key);
                deleteNode(temp);
                delete temp;
            }
            Node* newNode=new Node(key,value);
            mp[key]=newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */