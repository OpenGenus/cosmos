/*
	Binomial Heap : Priority Queue Data Structure using C++11
	@author:	github.com/138paulmiller
*/


#ifndef BINOMIALHEAP_H_
#define BINOMIALHEAP_H_


#define DEBUG false
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>

#include <string>
/*
	bnode -
		child    - points to node with value such that child value > parent value
		sibling  - points to node with shared parent, creates Single linked list between children
 */

template <typename T>
class BinomialNode;

template <typename T>
class BinomialHeap
{

public:
	struct Exception
	{
		Exception(std::string msg ):msg(msg){}
		std::string what(){return msg;}
		std::string msg;
	};
	friend class BinomialNode<T>;
	
	BinomialHeap();
	BinomialHeap(const BinomialHeap& other);
	BinomialHeap(BinomialHeap&& other);
	BinomialHeap& operator=(const BinomialHeap& other);
	~BinomialHeap();
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
	 * 		if key not found throws exception
	 */
	void deleteKey(T value);
	/*
	 * decreaseKey
	 * 		Searches for node with value v a
	 *
	 * 	value:
	 * 		value to find and decrease
	 * 	newValue:
	 * 		value to decrease value to
	 * returns
	 * 		if key not found throws exception
	 */
	void decreaseKey(T value, T newValue);
	/*
	 * size
	 * 		Number of nodes in heap.
	 *
	 * returns
	 *		number of nodes in heap
	 */
	int size();
	/*
	 * size
	 * 		Checks if empty
	 *
	 * returns
	 *		if empty
	 */
	bool isEmpty();
	/*
	 * clear
	 * 		Removes all elements
	 *
	 * returns
	 *		none
	 */
	void clear();
protected:
	/*Utility heap functions*/
	/*
	 * findKey
	 * 		Searches heap for node with value equal to key.
	 * 		v : value in heap to find
	 * 	returns
	 * 	 a pointer to node with value key
	 */
	BinomialNode<T>* findKey(T v);
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
	static BinomialNode<T>* unionHeap(BinomialNode<T>* heapA, BinomialNode<T>* heapB);
	/* mergeHeap
	 * 		Merges two heaps into a single Binomial heap by adding
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
	static BinomialNode<T>* mergeHeap(BinomialNode<T>* heapA, BinomialNode<T>* heapB);
	/*
	 * order
	 * 		Number of children incident on heap
	 * 	heap
	 * 		pointer to root of Binomial heap
	 * 	returns
	 * 		order or heap
	*/
	static int order(BinomialNode<T>* heap);

private:
	/*
	 * head
	 * 		pointer to the head of the heap list where every
	 * 		node is the root node of a heap
	 */
	BinomialNode<T> * head;
};

/*
											~~~~ BINOMIAL NODE  ~~~~
*/
template <typename T>
class BinomialNode
{
public:
	friend class BinomialHeap<T>;
	BinomialNode(T v, BinomialNode<T> * parent = nullptr);
	~BinomialNode();

	void addChild(BinomialNode<T>* child);
	BinomialNode<T>* find(T v);
	int size(int& i);
	//used to append all nodes visited in this data structure into the other
	void addTo(BinomialHeap<T>* other);
private:
	T value;
	BinomialNode<T> *sibling, *child, * parent;
	int order;
};

/*
										~~~~ BINOMIAL NODE DEFINITIONS ~~~~
*/

template <typename T>
BinomialNode<T>::BinomialNode(T v, BinomialNode<T> * p)
{
	value = v;
	parent = p;
	sibling = child = nullptr;
	order=  0;
}
template <typename T>
BinomialNode<T>::~BinomialNode()
{
	delete child;
	delete sibling;
}

template<typename T>
int BinomialNode<T>::size(int & i)
{
	++i;
	if(sibling)
		sibling->size(i);
	if(child)
		child->size(i);

	return i;
}


template <typename T>
void BinomialNode<T>::addChild(BinomialNode<T>* childNode)
{
	if(childNode)
	{
		childNode->sibling = nullptr;
		if(child)
		{
			BinomialNode<T>* temp = child;
			while(temp->sibling)
			{
				temp = temp->sibling;
			}
			temp->sibling = childNode;
		}
		else
		{
			child = childNode;
		}
		//
		++order;
		childNode->parent = this;
	}
}
template <typename T>
BinomialNode<T>* BinomialNode<T>::find(T v)
{
	BinomialNode<T>* found = nullptr;
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
void BinomialNode<T>::addTo(BinomialHeap<T> * other)
{

	other->insert(value);
	if(sibling)
	{
		sibling->addTo(other);
	}

	if(child)
	{
		child->addTo(other);
	}
}

/*
									~~~~ BINOMIAL HEAP DEFINITIONS ~~~~
*/
template <typename T>
BinomialHeap<T>::BinomialHeap()
{
	head = 0;
}

template <typename T>
BinomialHeap<T>::BinomialHeap(const BinomialHeap& other)
{
	//invoke = op
	*this = other;
}

template <typename T>
BinomialHeap<T>::BinomialHeap(BinomialHeap&& other)
{
	head=0;
	if(other.head)
		other.head->addTo(this);
	 other.clear();
}

template <typename T>
BinomialHeap<T>& BinomialHeap<T>::operator=(const BinomialHeap& other)
{
	head=0;
	if(other.head)
		other.head->addTo(this);
}



template <typename T>
BinomialHeap<T>::~BinomialHeap()
{
	clear();
}
template <typename T>
void BinomialHeap<T>::clear()
{
	delete head;
	head = nullptr;
}

template <typename T>
bool BinomialHeap<T>::isEmpty()
{
	return (head==0);
}


template <typename T>
void BinomialHeap<T>::insert(T v)
{
	BinomialNode<T> *p = head?  head->parent:  nullptr;
	BinomialNode<T> *singleton = new BinomialNode<T>(v, p);
	head = unionHeap(singleton, head);

}

template <typename T>
T BinomialHeap<T>::getMin()
{
	T min;
	if(head)
	{
		BinomialNode<T> * temp = head;
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
T BinomialHeap<T>::extractMin()
{
	BinomialNode<T> *prev=nullptr, 
					*min=nullptr, 
					*temp=nullptr, 
					*next=nullptr;
	T minValue;
	if(head)
	{
		BinomialNode<T>* minPrev = nullptr; //previous node of min node
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
		min->sibling = nullptr;
		min->child = nullptr;
		min->parent = nullptr;
		minValue=  min->value;
		delete min;
		/*
		 * Union the two detached heaps
		 */
		head = unionHeap(head, next);
		temp = min = minPrev = next= nullptr;
	}
	else
		throw BinomialHeap<T>::Exception("Empty Heap!");

	return minValue;
}

/*
 *
 */
template <typename T>
int BinomialHeap<T>::size()
{
	int i = 0;
	if(head)
		head->size(i);
	return i;
}

template <typename T>
void BinomialHeap<T>::deleteKey(T v)
{
	decreaseKey(v, getMin()-1); //set to min
	extractMin();
}

template <typename T>
void BinomialHeap<T>::decreaseKey(T v, T newV)
{
	if(head)
	{
		if(v > newV)
		{
			/*
			 * maintains heap property by bubbling current until parent > current
			 */
			BinomialNode<T> *current = head->find(v), 
							*parent = nullptr;
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
			}
			else
			{
				throw BinomialHeap<T>::Exception("Key not found!");
			}	
		}
		else
			throw BinomialHeap<T>::Exception("New Key must be less than current key!");
	}
	else
	{
		throw BinomialHeap<T>::Exception("Heap is empty!");
	}
}
template <typename T>
BinomialNode<T>* BinomialHeap<T>::findKey(T v)
{
	if(head)
	{
		return head->find(v);
	}
	return nullptr;
}

template <typename T>
int BinomialHeap<T>::order(BinomialNode<T>* heap)
{
	if(!heap)
		return -1;
	int i = 0;
	BinomialNode<T>* child = heap->child;
	while(child)
	{
		++i;
		child = child->sibling;
	}
	return i;
}


template <typename T>
BinomialNode<T>* BinomialHeap<T>::unionHeap(BinomialNode<T>* heapA, BinomialNode<T>* heapB)
{
	/*
	 * Merges heapA and heapB assuming both are sorted by heap order
	 * concatenates heaps of same order so that at most one tree of each order
	*/

	/*
	 * get merged heap of heapA and heapB
	 */
	BinomialNode<T>* heapU  = mergeHeap(heapA, heapB);
	if(heapU)
	{
		/*    prev   cur      next
		 * U-> |_|-> |_|->    |_|->
		 *            |        |
		 *           |_|->    |_|->
		 */
		BinomialNode<T>
			*cur = heapU,  // current node to append before or after
			*prev = nullptr, // node with sibling equal to current
			*next = nullptr; // the next potential
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
BinomialNode<T>* BinomialHeap<T>::mergeHeap(BinomialNode<T>* heapA, BinomialNode<T>* heapB)
{
	//modify to insert
	BinomialNode<T>* heapM = nullptr;//merged heap

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
			BinomialNode<T>*temp = nullptr, 
							*next = nullptr, 
							*prev = nullptr,
							*cur = nullptr;
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
