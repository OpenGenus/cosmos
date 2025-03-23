/*
Part of Cosmos by OpenGenus Foundation
*/

#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;

    bool myCompare(int a,int b){  /// returns a<b for min heap
        return a<b;
    }

    void heapify(int i){
        int left = i<<1;
        int right = left+1;
        int min_i = i;
        if(left<v.size() && myCompare(v[left],v[min_i])){
            min_i = left;
        }
        if(right<v.size() && myCompare(v[right],v[min_i])){
            min_i = right;
        }
        if(min_i!=i){
            swap(v[i],v[min_i]);
            heapify(min_i);
        }
    }

public:

    Heap(){
        v.push_back(-1);  /// Blocks position 0, we will start from 1
    }

    void push(int data){
        v.push_back(data);
        int index = v.size()-1;
        int parent = index/2;
        while(index>1 &&myCompare(v[index],v[parent])){
            swap(v[index],v[parent]);
            index = parent;
            parent = index/2;
        }
    }

    int getTop(){
        return v[1];
    }
    void pop(){
        int last_index = v.size()-1;
        swap(v[1],v[last_index]);
        v.pop_back();
        heapify(1);
    }
    bool isEmpty(){
        return v.size()==1;
    }
};


int main(){

    int nos[] = {5,4,1,3,2,6,7,8};

    Heap h;

    for(int i=0;i<8;i++){
        h.push(nos[i]);
    }
    while(!h.isEmpty()){
        cout<< h.getTop()<<" ";
        h.pop();
    }

return 0;
}
