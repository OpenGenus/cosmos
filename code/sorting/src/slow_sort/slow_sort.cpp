/* Part of Cosmos by OpenGenus Foundation */
#pragma once
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief implement the slowSort Algorithm
 * 
 * @param vect_ vector to be sorted
 * @param i ith index of vector
 * @param j jth index of vector
 */
void slowSort( vector<int32_t>& vect_, int i, int j )
{
    if( i >= j )
    {
        return;
    }

    int m = floor( ( i+j ) / 2 );
    slowSort( vect_, i, m );
    slowSort( vect_, m+1, j );

    if( vect_[j] < vect_[m] )
    {
        swap( vect_[j], vect_[m] );
    }

    slowSort( vect_, i, j-1 );
}

/**
 * @brief print the contents of vector A
 * 
 * @param vect_ vector whose index has to be printed
 */
void printVector( vector<int32_t>& vect_ )
{
    for(const auto& a : vect_)
    {
        cout << a << " ";
    }
}

int main()
{
    vector<int32_t> vect_;

    cout << " Enter elements of the vector: [Enter any character to end the while loop]\n";

    int32_t input;
    while(cin>>input)
    {
        vect_.push_back(input);
    }

    int i = 0;
    int j = vect_.size() - 1;

    cout << "Vector before sorting : \n";
    printVector( vect_ );

    slowSort(vect_, i, j);

    cout<<"\n";
    cout << "Vector after sorting : \n";
    printVector( vect_ );

    return 0;
}