/*
 * bheap.h
 *
 *  Created on: Apr 14, 2017
 *      Author: 138
 */

#ifndef BINOMIALHEAP_H_
#define BINOMIALHEAP_H_


#define DEBUG false
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>
/*
	Binomial Heap : Priority Queue Data Structure

	@author:	github.com/138paulmiller
*/
/*
	bnode -
		child    - points to node with value such that child value > parent value
		sibling  - points to node with shared parent, creates Single linked list between children
 */
template <typename T>
class binomialNode
{
public:
	binomialNode(T v, binomialNode<T> * parent = 0);
	~binomialNode();
	void addChild(binomialNode<T>* child);
	binomialNode<T>* find(T v);
	int size(int& i);
	void print( std::ostream& out);
	T value;
	binomialNode<T>* sibling, *child, * parent;
	int order;
};

template <typename T>
binomialNode<T>::binomialNode(T v, binomialNode<T> * p)
{
	value = v;
	parent = p;
	sibling = child = 0;
	order=  0;
}
template <typename T>
binomialNode<T>::~binomialNode()
{
	//std::cout << "\nDeleting " << value;

	if(child)
		delete child;

	if(sibling)
		delete sibling;

}

template<typename T>
int binomialNode<T>::size(int & i)
{
	i ++;
	if(sibling)
		sibling->size(i);
	if(child)
		child->size(i);

	return i;
}


template <typename T>
void binomialNode<T>::addChild(binomialNode<T>* childNode)
{
	if(childNode)
	{
		childNode->sibling = 0;
		if(child)
		{
			binomialNode<T>* temp = child;
			while(temp->sibling)
				temp = temp->sibling;
			temp->sibling = childNode;
		}
		else
		{
			child = childNode;
		}
		//
		order++;
		childNode->parent = this;
	}
}
template <typename T>
binomialNode<T>* binomialNode<T>::find(T v)
{
	binomialNode<T>* found = 0;
	if(v == value)
		return this;
	else if(sibling)
	{
		found =  sibling->find(v);
	}
	if( value < v && ! found) //if v is larger, check children,
	{
		if(child)
		{
			found =  child->find(v);
		}
	}

	return found;
}
template <typename T>
void binomialNode<T>::print(std::ostream& out)
{
	out << "\nNode : " << std::setw(5) << value;
	if(DEBUG)
	{
		out << "\tOrder:  " << order;
		out << "\tParent  : " ;
		if(parent) out  << std::setw(5) << parent ->value;
		out << "\tSibling : " ;
		if(sibling) out  << std::setw(5) << sibling->value;
		out << "\tChild   : " ;
		if(child) out << std::setw(5) << child->value;
		if(sibling && sibling->order < order)
			out << "********ERROR IN SIBLING ORDERING!!!******";
	}
	if(sibling)
		sibling->print(out);
	if(child)
			child->print(out);

}

template <typename T>
class binomialHeap
{
	friend class binomialNode<T>;

public:
	binomialHeap();
	~binomialHeap();
	/*
	 * insert
	 * 		Creates a singleton heap node with value v and
	 * 		 unions it with the head
	 * 	value:
	 * 		value to insert into heap
	 *
	 */
	void insert(T value);
	/*
	 * getMin
	 * 		Searches the heap list for the node with minimum value
	 *
	 * returns
	 * 		minimum value in heap list
	 */
	T getMin();
	/*
	 * extractMin
	 * 		Removes the heap list for node with minimum value
	 * 		and unions minimum node's children with heap list
	 *
	 * returns
	 * 		minimum value in heap list
	 */
	T extractMin();
	/*
	 * deleteKey
	 * 		Removes the node with the value v by decreasing
	 * 		node value to one less than current min and then
	 * 		extracts the min.
	 * value:
	 * 		value to delete from heap
	 *
	 * returns
	 * 		true if successfully deleted
	 */
	bool deleteKey(T value);
	/*
	 * decreaseKey
	 * 		Searches for node with value v a
	 *
	 * 	value:
	 * 		value to find and decrease
	 * 	newValue:
	 * 		value to decrease value to
	 * returns
	 * 		true if successfully decreased
	 */
	bool decreaseKey(T value, T newValue);
	/*
	 * size
	 * 		Number of nodes in heap.
	 *
	 * returns
	 *		number of nodes in heap
	 */
	int size();
	bool isEmpty();
	void print(std::ostream& out);
protected:
	/*Utility heap functions*/
	/*
	 * findKey
	 * 		Searches heap for node with value equal to key.
	 * 		v : value in heap to find
	 * 	returns
	 * 	 a pointer to node with value key
	 */
	binomialNode<T>* findKey(T v);
	/*
	 * unionHeap
	 * 		Consolidates two heaps by merging them into a single
	 * 		The heap is appended to the end of the child list to maintain child order
	 * 		of roots from min to max
	 * 		Assumes heapA and heapB siblings are ordered by root order(sibling count)
	 *
	 * 	HeapA - root of heap to union with heapB
	 * 	HeapB - root of heap to union with heapA
	 *
	 *
	 * 	returns
	 * 		the root of the heap representing the union of heapA and heapB
	 * 		such that the either heapA becomes a child of heapB or the reverse
	 */
	static binomialNode<T>* unionHeap(binomialNode<T>* heapA, binomialNode<T>* heapB);
	/* mergeHeap
	 * 		Merges two heaps into a single binomial heap by adding
	 * 		all siblings of heapA and heapB into a single heap containing
	 * 		all nodes in heapA and heapB.
	 * 		Assumes heapA and heapB siblings are ordered by root order(sibling count)
	 * 		Consolidating two heaps maintains merged ordering
	 *
	 * 	HeapA - root of heap to union with heapB
	 * 	HeapB - root of heap to union with heapA
	 *
	 * 	returns
	 * 		the root of the new heap that contains all heapA and heapB nodes
	 *
	 */
	static binomialNode<T>* mergeHeap(binomialNode<T>* heapA, binomialNode<T>* heapB);
	/*
	 * order
	 * 		Number of children incident on heap
	 * 	heap
	 * 		pointer to root of binomial heap
	 * 	returns
	 * 		order or heap
	*/
	static int order(binomialNode<T>* heap);
private:
	/*
	 * head
	 * 		pointer to the head of the heap list where every
	 * 		node is the root node of a heap
	 */
	binomialNode<T> * head;
};


template <typename T>
binomialHeap<T>::binomialHeap()
{
	head = 0;
}

template <typename T>
binomialHeap<T>::~binomialHeap()
{
	if (head)
		delete head;
}

template <typename T>
bool binomialHeap<T>::isEmpty()
{
	return (head==0);
}


template <typename T>
void binomialHeap<T>::insert(T v)
{
	binomialNode<T>*  p = head?  head->parent:  0;
	binomialNode<T> * singleton = new binomialNode<T>(v, p);
	head = unionHeap(singleton, head);

}

template <typename T>
T binomialHeap<T>::getMin()
{
	T min;
	if(head)
	{
		binomialNode<T> * temp = head;
		min = head->value;
		while(temp)
		{
			if(temp->value < min)
			{
				min = temp->value;
			}
			temp = temp->sibling;
		}

	}
	return min;
}
template <typename T>
T binomialHeap<T>::extractMin()
{
	binomialNode<T>*prev=0, *min=0, *temp=0, *next=0;
	T minValue;
	if(head)
	{
		binomialNode<T>* minPrev = 0; //previous node of min node
		min = head;
		temp = head->sibling;
		prev= head;
		/*
		 * Find min and minPrev of heaps
		 */
		while(temp)
		{
			if(temp->value < min->value)
			{
				min = temp;
				minPrev= prev;
			}
			prev= prev->sibling;
			temp = temp->sibling;
		}
		/*
		 *  If prev, assign prev sibling to min sibling.
		 *  Else if no prev min->sibling is new head
		 */
		if(minPrev)
		{
			minPrev->sibling=min->sibling;
		}
		else
		{
			head = min->sibling;
		}
		/*
		 * Update all children nodes parent pointers to null
		*/
		next = min->child;
		temp = next;
		while(temp)
		{
			temp->parent = min->parent;
			temp = temp->sibling;
		}
		/*
		 * Detach and delete min
		 */
		min->sibling = 0;
		min->child = 0;
		min->parent = 0;
		minValue=  min->value;
		delete min;
		/*
		 * Union the two detached heaps
		 */
		head = unionHeap(head, next);
		temp = min = minPrev = next= 0;
	}
	else
		std::cout << "\n\n ERROR couldn't not remove min!";

	return minValue;
}
template <typename T>
void binomialHeap<T>::print(std::ostream& out)
{
	if(head)
	{
		head->print(out);
	}

}
/*
 *
 */
template <typename T>
int binomialHeap<T>::size()
{
	int i = 0;
	if(head)
		head->size(i);
	return i;
}

template <typename T>
bool binomialHeap<T>::deleteKey(T v)
{
	if(decreaseKey(v, getMin()-1)) //set to min
	{
		extractMin();
		return true;
	}
	return false;
}

template <typename T>
bool binomialHeap<T>::decreaseKey(T v, T newV)
{
	if(v > newV)
	{
		/*
		 * maintains heap property by bubbling current until parent > current
		 */
		binomialNode<T>* current =  head->find(v), *parent = 0;
		T temp;
		if(current)
		{
			current->value = newV;
			parent = current->parent;

			while(current && parent && (current->value < parent->value))
			{
				temp = current->value;
				current->value = parent->value;
				parent->value  = temp;
				current = parent;
				parent = current->parent;
			}
			return true;
		}
		else
			std::cout << "\nKey not found to decrease";
	}
	else
		std::cout << "\nNew key should be less than old key!";
	return false;
}
template <typename T>
binomialNode<T>* binomialHeap<T>::findKey(T v)
{
	if(head)
	{
		return head->find(v);
	}
	return 0;
}

template <typename T>
int binomialHeap<T>::order(binomialNode<T>* heap)
{
	if(!heap)
		return -1;
	int i = 0;
	binomialNode<T>* child = heap->child;
	while(child)
	{
		i++;
		child = child->sibling;
	}
	return i;
}


template <typename T>
binomialNode<T>* binomialHeap<T>::unionHeap(binomialNode<T>* heapA, binomialNode<T>* heapB)
{
	/*
	 * Merges heapA and heapB assuming both are sorted by heap order
	 * concatenates heaps of same order so that at most one tree of each order
	*/

	/*
	 * get merged heap of heapA and heapB
	 */
	binomialNode<T>* heapU  = mergeHeap(heapA, heapB);
	if(heapU)
	{
		/*    prev   cur      next
		 * U-> |_|-> |_|->    |_|->
		 *            |        |
		 *           |_|->    |_|->
		 */
		binomialNode<T>
			*cur = heapU,  // current node to append before or after
				*prev = 0, // node with sibling equal to current
				*next = 0; // the next potential
		int orderA, orderB;
		while(cur && cur->sibling)
		{
			next = cur->sibling;
			orderA = cur->order;
			orderB = next->order;
			if(orderA == orderB && orderA != order(next->sibling))
			{
				//Next becomes Current's Child
				if(cur->value < next->value)
				{
					cur->sibling = next->sibling;
					cur->addChild(next);
					//tempNext->parent = cur;
					prev = cur;
					cur = cur->sibling;
				}
				else //Current becomes Next's Child
				{
					if(prev)
						prev->sibling = next;
					else
						heapU = next;
					next->addChild(cur);
					prev = next;
					cur = next->sibling;
				}
			}
			else
			{
				// got to Next's Child
				if(!prev)
					heapU = cur;
				prev = cur;
				cur = next;
			}
		}
	}

	return heapU;
}


template <typename T>
binomialNode<T>* binomialHeap<T>::mergeHeap(binomialNode<T>* heapA, binomialNode<T>* heapB)
{
	//modify to insert
	binomialNode<T>* heapM = 0;//merged heap

	if(heapA || heapB)
	{
		if(heapA && !heapB)
		{
			heapM = heapA;
		}
		else if(!heapA && heapB)
		{
			heapM = heapB;
		}
		else
		{
			binomialNode<T>*temp, *next, *prev = 0,*cur = 0;
			//pick minimum heap root to be merged heap root
			if(heapA->order > heapB->order)
			{
				heapM = heapB;
				next = heapA;

			}else
			{
				heapM = heapA;
				next = heapB;
			}
			cur = heapM;
			//Merges heap by reassigning sibling pointers
			while(cur && next && cur != next)
			{
				if(cur->order <= next->order)
				{
					if(cur->sibling)
					{
						temp = cur->sibling;
						cur->sibling = next;
						prev = cur;
						cur = next;
						next = temp;
					}
					else
					{
						cur->sibling = next;
						cur = next; // break loop
					}
				}
				else
				{
					if(prev)
						prev->sibling = next;
					else
						heapM = next;
					temp=next->sibling;
					next->sibling = cur;
					prev = next;
					next= temp;

				}
			}

		}
	}
	return heapM;
}


#endif /* BINOMIALHEAP_H_ */
