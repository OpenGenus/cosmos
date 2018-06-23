#ifndef _LINKED_LIST_CPP
#define _LINKED_LIST_CPP

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <list>
#include <vector>

template <typename Type>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const std::list<Type>& v);
	LinkedList(std::initializer_list<Type> list);
	virtual ~LinkedList();

	void add(Type value);
	LinkedList<Type>& addAll(const LinkedList<Type>& list);
	LinkedList<Type>& addAll(std::initializer_list<Type> list);

	Type& front();
	const Type& front() const;

	Type& back();
	const Type& back() const;

	Type popBack();
	Type popFront();

	void pushBack(const Type& value);
	void pushFront(const Type& value);

	// Removes first element equal to the value.
	void removeValue(const Type& value);

	// Removes all elements.
	void clear();

	void insert(int index, Type value);

	bool isEmpty() const;

	int size() const;

	Type& operator [](int index);
	const Type& operator [](int index) const;

	LinkedList operator +(const LinkedList& l2) const;
	LinkedList operator +(std::initializer_list<Type> list) const;

	bool operator ==(const LinkedList& list2) const;
	bool operator !=(const LinkedList& list2) const;

private:
	std::list<Type> _elements;

	class Iterator : public std::list<Type>::iterator
	{
	public:
		Iterator() : std::list<Type>::iterator(), pointer(nullptr) {}

		Iterator(const Iterator& it) : std::list<Type>::iterator(it), pointer(it.pointer) {}

		Iterator(LinkedList* pointer, const typename std::list<Type>::iterator& it)
				: std::list<Type>::iterator(it), pointer(pointer)
		{}

		Type& operator *()
		{
			return std::list<Type>::iterator::operator *();
		}

		Type* operator ->()
		{
			return std::list<Type>::iterator::operator ->();
		}
	private:
		LinkedList* pointer;
	};

	class ConstIterator : public std::list<Type>::const_iterator
	{
	public:
		ConstIterator() : std::list<Type>::const_iterator(), pointer(nullptr) {}

		ConstIterator(const ConstIterator& it) : std::list<Type>::const_iterator(it), pointer(it.pointer) {}

 		ConstIterator(const LinkedList* pointer, const typename std::list<Type>::const_iterator& it)
				: std::list<Type>::const_iterator(it),
				  pointer(pointer)
		{}

	private:
		const LinkedList* pointer;
	};


	Iterator begin()
	{
		return Iterator(this, _elements.begin());
	}

	ConstIterator begin() const
	{
		auto itr = _elements.begin();
		return ConstIterator(this, itr);
	}

	Iterator end()
	{
		auto itr = _elements.end();
		return Iterator(this, itr);
	}

	ConstIterator end() const
	{
		auto itr = _elements.end();
		return ConstIterator(this, itr);
	}
};


template <typename Type>
LinkedList<Type>::LinkedList() {}

template <typename Type>
LinkedList<Type>::LinkedList(const std::list<Type>& v) : _elements(v) {}

template <typename Type>
LinkedList<Type>::LinkedList(std::initializer_list<Type> list)
{
	addAll(list);
}

template <typename Type>
LinkedList<Type>::~LinkedList() {}

template <typename Type>
void LinkedList<Type>::add(Type value)
{
	_elements.push_back(value);
}

template <typename Type>
LinkedList<Type>& LinkedList<Type>::addAll(const LinkedList<Type>& list)
{
	for (const Type& value : list)
	{
		add(value);
	}
	return *this;
}

template <typename Type>
LinkedList<Type>& LinkedList<Type>::addAll(std::initializer_list<Type> list)
{
	for (const Type& value : list) 
	{
		add(value);
	}
	return *this;
}

template <typename Type>
Type& LinkedList<Type>::front()
{
	if (isEmpty()) 
	{
		std::cerr << "LinkedList::front: list is empty" << std::endl;
	}
	return _elements.front();
}

template <typename Type>
const Type& LinkedList<Type>::front() const
{
	if (isEmpty())
	{
		std::cerr << "LinkedList::front: list is empty" << std::endl;
	}
	return _elements.front();
}

template <typename Type>
Type& LinkedList<Type>::back()
{
	if (isEmpty())
	{
		std::cerr << "LinkedList::back: list is empty" << std::endl;
	}
	return _elements.back();
}

template <typename Type>
const Type& LinkedList<Type>::back() const
{
	if (isEmpty())
	{
		std::cerr << "LinkedList::back: list is empty" << std::endl;
	}
	return _elements.back();
}

template <typename Type>
Type LinkedList<Type>::popBack()
{
	if (isEmpty())
	{
		std::cerr << "LinkedList::pop_back: list is empty" << std::endl;
	}
	Type back = _elements.back();
	_elements.pop_back();
	return back;
}

template <typename Type>
Type LinkedList<Type>::popFront()
{
	if (isEmpty())
	{
		std::cerr << "LinkedList::pop_front: list is empty" << std::endl;
	}
	Type front = _elements.front();
	_elements.pop_front();
	return front;
}

template <typename Type>
void LinkedList<Type>::pushBack(const Type& value)
{
	_elements.push_back(value);
}

template <typename Type>
void LinkedList<Type>::pushFront(const Type& value)
{
	_elements.push_front(value);
}

template <typename Type>
void LinkedList<Type>::removeValue(const Type& value)
{
	auto itr = this->begin();
	auto end = this->end();
	while (itr != end)
	{
		if (*itr == value)
		{
			_elements.erase(itr);
			break;
		}
		itr++;
	}
}

template <typename Type>
void LinkedList<Type>::clear()
{
	_elements.clear();
}

template <typename Type>
void LinkedList<Type>::insert(int index, Type value)
{
	if (index < 0 || index > size())
	{
		std::ostringstream out;
		out << "LinkedList::insert" << ": index of " << index
			<< " is outside of valid range [" << size() << "]";
		std::cerr << out.str() << std::endl;
	}

	auto itr = _elements.begin();
	std::advance(itr, index);
	_elements.insert(itr, value);
}

template <typename Type>
bool LinkedList<Type>::isEmpty() const
{
	return _elements.empty();
}

template <typename Type>
int LinkedList<Type>::size() const
{
	return _elements.size();
}

template <typename Type>
Type& LinkedList<Type>::operator [](int index)
{
	if (index < 0 || index > size())
	{
		std::ostringstream out;
		out << "LinkedList::operator []" << ": index of " << index
			<< " is outside of valid range [" << size() << "]";
		std::cerr << out.str() << std::endl;
	}

	auto itr = _elements.begin();
	advance(itr, index);
	return *itr;
}

template <typename Type>
const Type& LinkedList<Type>::operator [](int index) const
{
	if (index < 0 || index > size())
	{
		std::ostringstream out;
		out << "LinkedList::operator []" << ": index of " << index
			<< " is outside of valid range [" << size() << "]";
		std::cerr << out.str() << std::endl;
	}

	auto itr = _elements.begin();
	advance(itr, index);
	return *itr;
}

template <typename Type>
LinkedList<Type> LinkedList<Type>::operator +(const LinkedList& list2) const
{
	LinkedList<Type> list = *this;
	return list.addAll(list2);
}

template <typename Type>
LinkedList<Type> LinkedList<Type>::operator +(std::initializer_list<Type> list) const
{
	LinkedList<Type> result = *this;
	return result.addAll(list);
}

template <typename Type>
bool LinkedList<Type>::operator ==(const LinkedList& list2) const
{
	return _elements == list2._elements;
}

template <typename Type>
bool LinkedList<Type>::operator !=(const LinkedList& list2) const
{
	return _elements != list2._elements;
}

#endif // _LINKED_LIST_CPP