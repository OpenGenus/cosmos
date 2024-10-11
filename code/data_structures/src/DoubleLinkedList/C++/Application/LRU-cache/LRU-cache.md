

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

# How to imagine LRU cache:

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

#### Let's say you have a fixed-size box, which can have plates and your name(value) written on it.
- It can accommodate only capacity no. of plates, ex: 3 plates 
- Always keep in mind🤯 *The value either updated or asked will be the most recent item/plate*.
- 🤔 You can perform two actions: 
1. Get the plate: Display the value of the key provided.
2. Put the value of the given key(similar to an unordered map).

Let's discuss cases:
## 🪄Case 1:
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

- if the plate is present output the value.
- else return -1 
## 🪄Case 2:
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

### Case (a). If the box is full:
        - And the plate isn't already present, Need to *delete the most recently used plate* and insert the given plate.
        - If the plate is present in the box then we need to first *delete that plate* and then again insert it with the updated values.
        
### Case (b). If the box *isn't* full:
        - And if the plate isn't present already, we'll add this plate to the box.
        - If the plate is present in the box then we need to first *delete that plate* and then again insert it with the updated values.


<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

# 🥳 Introduction to LRU cache:
1. LRU cache is a type of cache that stores a limited number of items based on their usage patterns.
2. The cache has a fixed capacity and when it reaches its limit, the least recently used item is evicted to make room for new entries.
3. LRU cache is designed to optimize memory usage by keeping frequently used items in the cache while removing the least recently used ones.
4. It is commonly implemented using a combination of a hash map and a doubly linked list.
5. The hash map provides fast access to cache items by their keys, allowing constant-time lookup.
6. The doubly linked list maintains the order of the items based on their usage, with the most recently used item at the front and the least recently used item at the end.
7. When an item is accessed or added to the cache, it is moved to the front of the linked list, indicating that it is the most recently used item.
8. Eviction occurs when a new item is added to a full cache or when an existing item is accessed. In both cases, the item at the end of the linked list (the least recently used item) is removed.
9. The LRU cache algorithm has a time complexity of O(1) for both cache lookups and item insertions/removals, assuming the hash map and linked list operations are implemented efficiently.
10. LRU cache is widely used in various applications, such as databases, web servers, and caching systems, to improve performance by reducing the number of expensive disk or network operations.
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">


- Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

- PUT x y: sets the value of the key x with value y
- GET x: gets the key of x if present else returns -1.

#### The LRUCache class has two methods get() and put() which are defined as follows.

- get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
- put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.

## ✅ Implementation:


```


class Node{
        public:
            // queue using doubly linked list
            int key;
            int value;
            Node* next;
            Node* prev;

            //constructor
            Node(int key, int value){
                this->key = key;
                this->value = value;
                this->next = NULL;
                this->prev = NULL;
            }
        
};
    
class LRUCache {
public:
   // unordered map for storing address corresponding to key  
    Node* front;
    Node* rear;
    int capacity;
    int length;
    unordered_map<int, Node*> dict;
    
public:
    
    LRUCache(int cap) {
       front = NULL;
        rear = NULL;
        capacity = cap;
        length = 0;
    }
    
    void enqueue(int key , int value){
        Node* ptr = new Node(key , value);
        // storing address of key in map
        dict[key] = ptr;
        length++;
        
        if(front == NULL){
            front = ptr;
            rear = ptr;
        }else{
            ptr->prev = rear;
            rear->next = ptr;
            rear = ptr;
        }
    }
    
    
    int dequeue(){
        if(front == NULL){
            return -1;
        }else{
            int deleted = front->value;
             // erasing the value(address) of coressponding key from map
            
            dict.erase(dict.find(front->key));
            Node* ptr = front;
            front = front->next;
            // now if front becomes null then rear and front both will point to null
            if(front == NULL){
                rear = NULL;
            }
            delete(ptr);
            length--;
            return deleted;
        }
    }
    
    // for debugging
    void display(){
        for(pair<int , Node*> p:dict){
            cout<<p.first<<" : "<<p.second<<" , ";
        }
        cout<<"\n";
        Node* x = front;
        while(x != NULL){
            cout<<x->key<<" , ";
            x = x->next;
        }
        cout<<"\n\n";
    }
    
    int deleteKey(int key){
        if(front == NULL || dict.find(key) == dict.end()){
            return -1;
        }else{
            //
            Node* ptr = dict[key];
            
            if(ptr == front){
               return dequeue();
            }else if(ptr == rear){
                rear = rear->prev;
                dict.erase(dict.find(key));
                int deleted = ptr->value;
                delete(ptr);
                rear->next = NULL;
                length--;
                return deleted;
            }else{
                Node* x = ptr->prev;
                Node* y = ptr->next;
                y->prev = x;
                x->next = y;
                dict.erase(dict.find(key));
                int deleted = ptr->value;
                length--;
                delete(ptr);
                return deleted;
            }     
        }
    }
    
    
    
    int get(int key) {
        if(dict.find(key) == dict.end()){
            return -1;
        }else{
            int value = deleteKey(key);
            enqueue(key , value);
            return value;
        }      
    }
    
    void put(int key, int value) {
        if(length == capacity){
            if(dict.find(key) == dict.end()){
                dequeue();
                enqueue(key , value);
            }else{
                deleteKey(key);
                enqueue(key , value);
            }
        }else{
            if(dict.find(key) == dict.end()){
                enqueue(key , value);
            }else{
                deleteKey(key);
                enqueue(key , value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


```
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">
