#include<iostream>
#include<cstdlib>
#include<map>

using namespace std;

int main()
{
    //common way to initialize a multimap
    std::multimap<char, int> m; //empty multimap container
    m.insert({'a',1}); //inserting (a,1)
    m.insert({'a',1}); //inserting (a,1)
    m.insert({'b',2}); //inserting (b,2)
    m.insert({'c',3}); //inserting (c,3)
    m.insert({'a',2}); //inserting (a,2)
    m.insert({'d',4}); //inserting (d,4)

    //Method 1
    std::multimap<char, int> m; //empty multimap container
    m.insert(make_pair('a',1)); //inserting (a,1)
    m.insert(make_pair('a',1)); //inserting (a,1)
    m.insert(make_pair('b',2)); //inserting (b,2)
    m.insert(make_pair('c',3)); //inserting (c,3)
    m.insert(make_pair('a',2)); //inserting (a,2)
    m.insert(make_pair('d',4)); //inserting (d,4)

    //Method 2
    pair<char, int> x;
    std::multimap<char, int> m; //empty multimap container
    x.first='a';x.second=1;
    m.insert(x);                //inserting (a,1)
    x.first='a';x.second=1;
    m.insert(x);                //inserting (a,1)
    x.first='b';x.second=2;
    m.insert(x);                //inserting (b,2)
    x.first='c';x.second=3;
    m.insert(x);                //inserting (c,3)
    x.first='a';x.second=2;
    m.insert(x);                //inserting (a,2)
    x.first='d';x.second=4;
    m.insert(x);                //inserting (d,4)
   
   //Method 3
    std::multimap<char, int> m; //empty multimap container
    m.insert(pair<char, int>('a',1)); //inserting (a,1)
    m.insert(pair<char, int>('a',1)); //inserting (a,1)
    m.insert(pair<char, int>('b',2)); //inserting (b,2)
    m.insert(pair<char, int>('c',3)); //inserting (c,3)
    m.insert(pair<char, int>('a',2)); //inserting (a,2)
    m.insert(pair<char, int>('d',4)); //inserting (d,4)

    //Method 4
    std::multimap<char, int> m={
        {'a',1}, {'a',1}, {'b',2}, {'c',3}, {'a',2}, {'d',4}
    };

    //Method 5
    std::multimap<char, int> n(m.begin(),m.end());

    //Method 6
    std::multimap<char, int> n(m);
   
    //Method 7
    std::multimap<char, int> mp;
    mp.emplace_hint(mp.begin(), 'a', 1); 
    mp.emplace_hint(mp.begin(), 'a', 1); 
    mp.emplace_hint(mp.begin(), 'b', 2); 
    mp.emplace_hint(mp.begin(), 'c', 3);  
    mp.emplace_hint(mp.begin(), 'a', 2);  
    mp.emplace_hint(mp.begin(), 'd', 4);  

    //Printing contents of the multimap :
    //Method 1
    for(auto& el : mp)
    cout<<el.first<<" "<<el.second<<endl;

    //Method 2
    multimap<char, int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        cout<<it->first<<" "<<it->second<<"\n";

    //Method 3
    for(pair<char, int> elem: m)
        cout<<elem.first<<" "<<elem.second<<endl;

    return 0;
}

