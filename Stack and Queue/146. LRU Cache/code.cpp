// Used DLL & map

class Node{
public:
    int key, val;
    Node *prev, *next;
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int,Node*> mp;
    int cap=-1;
    Node *head, *tail;
    void deleteNode(Node *node){
        Node* prevnode=node->prev;
        Node* afternode=node->next;
        prevnode->next=afternode;
        afternode->prev=prevnode;
    }
    void insertAfterHead(Node *node){
        Node *curr=head->next;
        head->next=node;
        node->next=curr;
        curr->prev=node;
        node->prev=head;
    }

public:
    LRUCache(int capacity) {
        cap=capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node=mp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mp.size()==cap){
                Node* node= tail->prev;
                mp.erase(node->key);
                deleteNode(node);         
            }
            Node * newnode=new Node(key,value);
            mp[key]=newnode;
            insertAfterHead(newnode);
        }
    }
};
