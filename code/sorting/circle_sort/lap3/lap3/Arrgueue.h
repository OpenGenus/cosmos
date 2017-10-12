#pragma once
template <class T>
class Arrgueue
{

	T *Arr;
	T *ArrExpand;
	int cap;
	int element;
	int front;
	int back;
public:
	Arrgueue(int);
	~Arrgueue();
	void enqueue(T);
	void dequeue();
	T Front();
	void Expand();

};

