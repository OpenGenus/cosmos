#ifndef NODO_H
#define NODO_H
// A C++ program to demonstrate operations of KD tree
#include<bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <array>
//#include "kd_tree.h"
#include <sstream>
#include <string>


using namespace std;


/////////////////funciones////////////////////


// A structure to represent node of kd tree
class Node{
public:
    int altura;
    vector<double> point;
    //int point[k]; // To store k dimensional point
    Node *left, *right;
    int k=2;

// A method to create a node of K D tree

// A utility method to determine if two Points are same
// in K Dimensional space

///////////////////////////////////////////////////
};
#endif // NODO_H
