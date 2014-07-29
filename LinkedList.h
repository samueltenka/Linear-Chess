#include <cstdlib>


//////////////////////////////////////////
// Example Usage:
// -------------
//
//	LinkedList<int> L;
//	L.append(1);
//	L.append(2);
//	L.append(4);
//	L.append(8);
//	for(LLIterator<int> i(L); i.can_continue(); i.next())
//	{
//		cout << i.value() << endl;
//	}
//
//////////////////////////////////////////

#ifndef LINKED_LIST
#define LINKED_LIST

template<typename T>
struct LLNode
{
	T value;
	LLNode<T>* successor;
	LLNode(): successor(NULL) {}
};

template<typename T>
class LLIterator
{
private:
	template<typename T>
	friend class LinkedList;
	LLNode<T>* node;
	LLIterator(LLNode<T>* n): node(n) {}
public:
	LLIterator(LinkedList<T>& LL):
		node(LL.start) {}
	bool can_continue() {return node->successor != NULL;}
	void next() {node = node->successor;}
	T& value() {return node->value;}
};

template<typename T>
class LinkedList
{
private:
	template<typename T>
	friend class LLIterator;
	LLNode<T>* start;	// half-open: [start, end); in particular,
	LLNode<T>* end;		// end doesn't contain anything itself. 

public:
	LinkedList()
	{
		end = new LLNode<T>;
		start = end;
	}
	void append(T element)
	{
		end->value = element;
		end = (end->successor = new LLNode<T>());
	}
	~LinkedList()
	{
		for(LLNode<T>* i = start; i != end; )
		{
			LLNode<T>* next = i->successor;
			delete i;
			i = next;
		}
		delete end;
	}
};
#endif
