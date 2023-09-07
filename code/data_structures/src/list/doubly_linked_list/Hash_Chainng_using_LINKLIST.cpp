#include <bits/stdc++.h>
#include <list>
using namespace std;
class Hash
{
    public:
    int bucket;
    list<int> *table;
    Hash(int b)
    {
        bucket=b;
        table= new list<int>[bucket];
    }

int hash_func(int item)
{
    return (item % bucket);
    //returns index 
}
void insert_item(int data)
{
    int index=hash_func(data);//index stored
    table[index].push_back(data);//inserted to link list
}
void delete_item(int data)
{
    int index=hash_func(data);//find index of data first
    list<int> :: iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)//search data
    {
        if(*i==data)
        {
            break;//break if key is found now its time to remove it
        }
    }
    if(i!=table[index].end())//if data found then erase from link list
    {
        table[index].erase(i);
    }
}
void display_hash()//to display 
{
    for(int i =0 ;i<bucket;i++)
    {
        cout<<i;//index printed
        for(auto x : table[i])
        {
            cout<<" ---> "<<x;//link list printed
        }
        cout<<endl;
    }
}
};

int main()
{

	int arr[] = { 15,11,27,8,12 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int b;
	cout<<"ENTER SIZE OF BUCKET : "<<endl;
	cin>>b;
	Hash h(b);
	for(int i=0;i<n;i++)
    {
        h.insert_item(arr[i]);
    }
    h.display_hash();

	return 0;
}
