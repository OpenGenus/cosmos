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
