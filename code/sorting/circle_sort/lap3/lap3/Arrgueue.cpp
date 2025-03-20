#include "Arrgueue.h"
#include <algorithm>
#include <iostream>
template <class T>
Arrgueue<T>::Arrgueue(int c)
{
	Arr = new T[c];

	cap = c ;
	ArrExpand = new T[c + 1];
	element = 0;
	front = -1;
	back = -1;

	 
}
template <class T>

void Arrgueue<T>::enqueue(T val){
	if (element == cap){
		Expand();
	}
	if (element == 0){
		front = 0;
	}
	element++;
	back = (back++%cap);
	Arr[back] = val;
}
template <class T>
void Arrgueue<T>::dequeue(){
	if (element == 1){
		front = -1;
		back - 1;

	}
	else {
		front = front++%cap;
	}
	element--;
}
template <class T>

T Arrgueue<T>::Front(){
	return Arr[front];
}

template <class T>
void Arrgueue<T>::Expand( ){
	for (int i = 0; i <element; i++){
		ArrExpand[i] = Arr[i];
	}
	
	cap++;
	delete[]Arr;
	Arr = ArrExpand;
}

template <class T>

Arrgueue<T>::~Arrgueue()
{
	delete[] Arr;
}
