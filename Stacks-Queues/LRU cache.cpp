/* Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity. */
//CODE

class LRUCache {
public:
    //structure of our node
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
            node(int _key, int _val){   //constructor
                key = _key;
                val = _val;
            }
    };
    
    //make 2 nodes, head and tail
    node *head = new node (-1, -1);
    node *tail = new node(-1, -1);
    
    int cap;    //capacity of LRU cache
    unordered_map<int, node*>m;     //a hash table which has the key and the node address
    
    LRUCache(int capacity) {    //constructor
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    //adding a new node
    void addnode(node *newnode){
        node *temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    
    //deleting a node
    void deletenode(node *delnode){
        node *delprev = delnode -> prev;
        node *delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key_) {
        if(m.find(key_) != m.end()){    //check if the node requested is present in hash table or not
            node *resnode = m[key_];    //then we get the node from the hash table;
            int res = resnode -> val;   //get the node's value
            m.erase(key_);             //delete the entry from the hash table
            deletenode(resnode);        //delete the node
            addnode(resnode);           //add the node after the head node so make it most recently used
            m[key_] = head -> next;    //hashtable will store the address of the head's next node;
            return res;                 //return the requested node's value
            
        }
        return -1;                      //if the value is not present, return -1
        
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()){        //before putting the value, check if it exists or not
            node *existingnode = m[key_];    //get the address
            m.erase(key_);                     //remove from hashtable
            deletenode(existingnode);           //delete the node
        }
        
        if(m.size()==cap){              //if the capacity is full
            m.erase(tail->prev->key);    //erase the least recently used value from hash table
            deletenode(tail->prev);        //delete the same from doubly linked list
        }
        addnode(new node(key_, value));     //add the new node
        m[key_] = head -> next;             //add the same in the hash table
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
