class Node {
    public:
    int key; int val;
    Node *prev, *next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }
    
};
class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int capacity, cap = 0;
    Node *head, *tail;
    void insertAtHead(Node* &head, Node* &node1) {
        Node* headNext = head->next;
        head->next = node1;
        node1->next = headNext;
        headNext->prev = node1;
        node1->prev = head;
    }

    void deleteNode(Node* &node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {
        mpp.clear();
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }
        
        Node* node1 = mpp[key];
        deleteNode(node1);
        insertAtHead(head, node1);
        
        return node1->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
           Node* node = mpp[key];
           node->val = value;
           deleteNode(node);
           insertAtHead(head, node);
        }
        else {
            if (mpp.size() == capacity) {
                Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAtHead(head, node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */