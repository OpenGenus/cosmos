/*
Least Recently Used Page Replacement Algorithm implemented using a stack
*/

#include <bits/stdc++.h>
using namespace std;

/*
 A function that finds and returns the index of the current page in the page table
 If it is not present it would return -1
 */
int find(int current_page,vector<int>& page_table){
    for(int i=0;i<page_table.size();i++)
        if(page_table[i]==current_page)
            return i;
    return -1;
}

int main(){
    int frames,pages,page_fault=0,page_hit=0;
    cout<<"Enter the number of Frames"<<endl;
    cin>>frames;
    cout<<"Enter the number of Page numbers in memory references"<<"\nNote : The page number has to be non - negative "<<endl;
    cin>>pages;
    vector<int>page_numbers(pages,-1); // Stores the sequence of page numbers given as I/P by the user
    // Note : The page number has to be non - negative 

    cout<<"Enter the sequence of memory references i.e page numbers"<<endl;
    
    // Storing the sequence of page numbers
    for(int i=0;i<pages;i++){
        cin>>page_numbers[i];
    }
    
    // Initialising the storage matrix
    int matrix[frames][pages]; // A storage matrix, that we will use to visualise the LRU algorithm and the stack
    for(int i=0;i<frames;i++){
        for(int j=0;j<pages;j++)
            matrix[i][j] = 0;
    }

    vector<int>page_table(frames,-1); // page_table is the stack that is used for LRU Page Replacement
    // Note I'm using -1 as my reference to indicate that the frame is empty
    /*
    Loops through each page number from the sequence given by user and implements demand paging i.e
    replaces Least Recently Used (LRU) page for this page if there is a shortage of pages, else would 
    add the page to the stack i.e allot a frame
    */
    for(int i=0;i<pages;i++){
        int index_of_current_page; // The index of the page if present,else -1
        int current_page = page_numbers[i];
        index_of_current_page = find(current_page,page_table);
        
        // If current page is not there in the page table i.e a page fault
        if(index_of_current_page ==-1){
            page_fault++;
            page_table.erase(page_table.begin()); // Erase the LRU Page i.e the bottom of the stack
        }

        // The current page is already present in the page table i.e page hit
        else{
            page_hit++;
            page_table.erase(page_table.begin() + index_of_current_page); 
        }
        
        /*
        Update the page to the top of the stack -> this is indepent of page fault or page hit
        Because the top of the stack contains the Most Recently used page and bottom of the stack hold the 
        Least Recently used page
        */
        page_table.push_back(current_page);

        // Storing the snapshot of the present page table in the matrix
        for(int j=0;j<frames;j++)
            matrix[j][i] = page_table[frames-j-1];
    }

    cout<<"\n \n";

    // Displaying all the snapshots of the page table taken for each time unit i.e page hit or page fault
    for(int i=0;i<frames;i++){
        if(i==frames-1)
            cout<<"LRU Page ->"<<" ";
        else 
            cout<<"            ";
        for(int j=0;j<pages;j++){
           printf("%2d ",matrix[i][j]);
        }
        cout<<endl;
    }
    float page_hit_ratio = page_hit;
    page_hit_ratio = page_hit_ratio/pages;
    float page_fault_ratio = page_fault;
    page_fault_ratio = page_fault_ratio/pages;
    cout<<"Page Hit ratio : "<<page_hit_ratio<<endl;
    cout<<"Page Fault ratio : "<<page_fault_ratio<<endl;
    cout<<"Note I'm using -1 as my reference to indicate that the frame is empty"<<endl;
    return 0;
}
// Note I'm using -1 as my reference to indicate that the frame is empty in the page table and it would reflect in the output also




/*
Example : 

I/P :

Frames : 3, Number of pages in sequence : 20
Memory reference sequence of page numbers : 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1


O/P :
             7  0  1  2  0  3  0  4  2  3  0  3  2  1  2  0  1  7  0  1 
            -1  7  0  1  2  0  3  0  4  2  3  0  3  2  1  2  0  1  7  0 
LRU Page -> -1 -1  7  0  1  2  2  3  0  4  2  2  0  3  3  1  2  0  1  7
Page Hit ratio : 0.4
Page Fault ratio : 0.6
*/