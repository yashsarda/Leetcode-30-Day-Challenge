/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the 
least recently used item before inserting a new item.

The cache is initialized with a positive capacity.
*/
/*
We want both the operations in O(1) time complexity.
We need to use a data structure.
DLL + HashMap solves this problem most efficiently
Node in a DLL :- Attributes key, value, prev, next pointers
DLL :- pointer to a front and pointer to rear node
HashMap :- Key = key and value = Node
Head of DLL denotes the most recently used item. Subsequently the rear will denote the least recently used item
1. get(key) 
if key is already in the hashmap, then return that item and move this item to head of LL
if key is not present, return -1;

2. put(key, value)
if size of DLL is less than capacity then add the node to the head of the DLL.
else size of DLL is equal to capacity, then evict the LRU item and push this to front of the DLL.
If the node is already in the cache, then push to the head of the LL
*/

/*
Takes good care of OOP principles as well
*/
struct Node {
    // By default public field
    int key;
    int value;
    Node* prev;
    Node* next;
    
    public:
        Node() : prev(nullptr), next(nullptr) {} 
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DLL {
    Node* front;
    Node* rear;
    
    public:
        DLL() : front(nullptr), rear(nullptr) {}
    
    // Adds a new node to the head of the DLL
    Node* add_to_head(int key, int value) 
    {
        Node* page = new Node(key, value);
        if(!front && !rear) {
            front = rear = page;
        }
        else {
            front -> prev = page;
            page -> next = front;
            front = page;
        }
        
        return page;
    }
    
    // Moves a node present in the DLL to the head 
    void move_to_head(Node* page) 
    {
        if(front == page)
            return;
        
        if(page == rear) {
            rear -> prev -> next = nullptr;
            rear = rear -> prev;
        }
        else {
            page -> prev -> next = page -> next;
            page -> next -> prev = page -> prev;
        }
        
        page -> next = front;
        front -> prev = page;
        front = page;
        page -> prev = nullptr;
    }
    
    // Removes the LRU item from the DLL
    void remove_from_rear() 
    {
        if(!rear)
            return;
        
        if(rear == front) {
            delete(rear);
            rear = front = nullptr;
        }
        else {
            Node* temp = rear;
            rear = rear -> prev;
            rear -> next = nullptr;
            delete(temp);
        }
    }
    
    // Required for updating the hashMap
    Node* getRear() 
    {
        return rear;
    }
    
};

class LRU {
    
    int size;
    int capacity;
    DLL* dll;
    unordered_map<int, Node*> hashMap;
    
    public:
        LRU(int cap) : size(0), capacity(cap) {
            dll = new DLL();   
        }
    
    int get_item(int key)
    {
        if(hashMap.find(key) != hashMap.end()) {
            int return_value =  hashMap[key] -> value;
            dll -> move_to_head(hashMap[key]);
            return return_value;
        }
        return -1;
    }
    
    void put_item(int key, int value)
    {
        if(hashMap.find(key) != hashMap.end()) {
            hashMap[key] -> value = value;
            dll -> move_to_head(hashMap[key]);
            return;
        }
        
        if(size == capacity) {
            int k = dll -> getRear() -> key;
            hashMap.erase(k);
            dll -> remove_from_rear();
            size--;
        }
        
        Node* page = dll -> add_to_head(key, value);
        size++;
        hashMap[key] = page;
    }
};

class LRUCache {
    LRU* lru;
public:
    LRUCache(int capacity) {
        lru = new LRU(capacity);
    }
    
    int get(int key) {
        return lru -> get_item(key);
    }
    
    void put(int key, int value) {
        lru -> put_item(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */