/*
 * Part of Cosmos by OpenGenus Foundation
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>

class process {
    public:
    size_t size;
    pid_t id;
};

class memory {
    public:
    size_t size;
    pid_t id;
    std::queue<process> allocated_processess;

    void push(const process p) {
        if(p.size <= size) {
            allocated_processess.push(p);
            size -= p.size;
        }
    }

    process pop(){
        if(!allocated_processess.empty()) {
            process process_to_pop = allocated_processess.front();
            allocated_processess.pop();
            size += process_to_pop.size;
            return process_to_pop;
        }
    }

    bool empty() {
        return allocated_processess.empty();
    }
};

std::vector<memory> first_fit(std::vector<memory>memory_blocks, std::queue<process>unallocated_processess) {
    memory nonAllocatedProcessess;
    nonAllocatedProcessess.id = -1;
    nonAllocatedProcessess.size = 0;

    while(!unallocated_processess.empty()) {
        int temp_p_id = unallocated_processess.front().id;
        for(int i = 0; i < memory_blocks.size(); ++i) {
            if(memory_blocks.at(i).size >= unallocated_processess.front().size) {
                memory_blocks.at(i).push(unallocated_processess.front());
                unallocated_processess.pop();
                break;
            }
        }

        if(temp_p_id == unallocated_processess.front().id) {
            nonAllocatedProcessess.size += unallocated_processess.front().size;
            nonAllocatedProcessess.push(unallocated_processess.front());
            unallocated_processess.pop();
        }
    }

    if(!nonAllocatedProcessess.empty()) {
        memory_blocks.push_back(nonAllocatedProcessess);
    }

    return memory_blocks;
}

void display(std::vector<memory> memory_blocks) 
{ 
    int i = 0, temp = 0; 
    process p; 
    std::cout << "+-------------+--------------+--------------+"
         << std::endl; 
    std::cout << "| Process Id | Process size | Memory block |"
         << std::endl; 
    std::cout << "+-------------+--------------+--------------+"
         << std::endl; 
  
    // Traverse memory blocks size 
    for (i = 0; i < memory_blocks.size(); i++) { 
  
        // While memory block size is not empty 
        while (!memory_blocks.at(i).empty()) { 
            p = memory_blocks.at(i).pop(); 
            temp = std::to_string(p.id).length(); 
            std::cout << "|" << std::string(7 - temp / 2 - temp % 2, ' ') 
                 << p.id << std::string(6 - temp / 2, ' ') 
                 << "|"; 
  
            temp = std::to_string(p.size).length(); 
            std::cout << std::string(7 - temp / 2 - temp % 2, ' ') 
                 << p.size 
                 << std::string(7 - temp / 2, ' ') << "|"; 
  
            temp = std::to_string(memory_blocks.at(i).id).length(); 
            std::cout << std::string(7 - temp / 2 - temp % 2, ' '); 
  
            // If memory blocks is assigned 
            if (memory_blocks.at(i).id != -1) { 
                std::cout << memory_blocks.at(i).id; 
            } 
  
            // Else memory blocks is assigned 
            else { 
                std::cout << "N/A"; 
            } 
            std::cout << std::string(7 - temp / 2, ' ') 
                 << "|" << std::endl; 
        } 
    } 
    std::cout << "+-------------+--------------+--------------+"
         << std::endl; 
} 
  
int main() 
{ 
    std::vector<memory> memory_blocks(5);   
    std::vector<memory> first_fit_blocks;  
    std::queue<process> processess; 
    process temp; 
  
    memory_blocks[0].id = 1; 
    memory_blocks[0].size = 400; 
  
    memory_blocks[1].id = 2; 
    memory_blocks[1].size = 500; 
  
    memory_blocks[2].id = 3; 
    memory_blocks[2].size = 300; 
  
    memory_blocks[3].id = 4; 
    memory_blocks[3].size = 200; 
  
    memory_blocks[4].id = 5; 
    memory_blocks[4].size = 100; 
  
    temp.id = 1; 
    temp.size = 88;   
    processess.push(temp); 
  
    temp.id = 2; 
    temp.size = 192;  
    processess.push(temp); 
  
    temp.id = 3; 
    temp.size = 277;  
    processess.push(temp); 
  
    temp.id = 4; 
    temp.size = 365;  
    processess.push(temp); 
  
    temp.id = 5; 
    temp.size = 489; 
    processess.push(temp); 
  
    first_fit_blocks = first_fit(memory_blocks, processess); 
  
    display(first_fit_blocks); 
    memory_blocks.clear(); 
    memory_blocks.shrink_to_fit(); 
    first_fit_blocks.clear(); 
    first_fit_blocks.shrink_to_fit(); 
    return 0; 
}
