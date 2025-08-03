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
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next=tail;
        tail->prev=head;
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        deleteNode(mp[key]);
        insertAfterHead(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }

    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insertAfterHead(Node* node){
        Node* nextNode=head->next;
        node->prev=head;
        node->next=nextNode;
        nextNode->prev=node;
        head->next=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */