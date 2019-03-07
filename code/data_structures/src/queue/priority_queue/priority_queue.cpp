// C++ implementation of Priority Queue

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
 
// Node Declaration
struct node{
	int priority;
	int info;
	node *link;
};

class PriorityQueue{
    private:
        node *front;
    public:
        PriorityQueue(){
            front = nullptr;
        }
        // Insert into Priority Queue
        void add(int item, int priority){
            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority = priority;
            if (front == nullptr || priority < front->priority){
                tmp -> link = front;
                front = tmp;
            }
            else{
                q = front;
                while (q->link != nullptr && q->link -> priority <= priority)
                    q = q->link;

                tmp->link = q->link;
                q->link = tmp;
            }
        }
        
        // Delete from Priority Queue
        void remove(){
            node *tmp;
            if(front == nullptr)
                std::cout << "Queue Underflow\n";
            else{
                tmp = front;
                std::cout << "Removed item is: " << tmp->info << "\n";
                front = front->link;
                free(tmp);
            }
        }
        
        // Print Priority Queue
        void display(){
            node *ptr;
            ptr = front;
            if (front == nullptr)
                std::cout << "Queue is empty\n";
            else{	
                std::cout << "Queue is :\n";
                std::cout << "Priority Item\n";
                while(ptr != nullptr){
                    std::cout << ptr->priority << "\t\t" << ptr->info << "\n";
                    ptr = ptr->link;
                }
            }
        }
};

int main(){

    int choice, item, priority;
    PriorityQueue pq; 

    do{
        std::cout << "1.Insert\n";
        std::cout << "2.Delete\n";
        std::cout << "3.Display\n";
        std::cout << "4.Quit\n";
        std::cout << "Enter your choice : "; 
        std::cin >> choice;
        switch(choice){
        case 1:
            std::cout << "Input the item value : ";
            std::cin >> item;
            std::cout << "Enter its priority : ";
            std::cin >> priority;
            pq.add(item, priority);
            break;
        case 2:
            pq.remove();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default :
            std::cout << "Wrong Choice !!!\n";
        }
    }
    while(choice != 4);

    return 0;
}
