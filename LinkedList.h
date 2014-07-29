#include <cstdlib>


//////////////////////////////////////////
// Example Usage of 2-way Linked List:
// ----------------------------------
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
	LLNode<T>* predecessor;
	LLNode<T>* successor;
	LLNode(): predecessor(NULL), successor(NULL) {}
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
	bool can_regress() {return node->successor != NULL;}
	void next() {node = node->successor;}
	void prev() {node = node->predecessor;}
	T& value() {return node->value;}
};

template<typename T>
class LinkedList
{
private:
	template<typename T>
	friend class LLIterator;
	LLNode<T>* start;	// half-open: [start, end); in particular,
	LLNode<T>* end;		// end doesn't contain anything itself, and 
						// end->successor == NULL.

public:
	LinkedList()
	{
		end = new LLNode<T>;
		start = end;
	}
	void append(T element)	// don't worry about loops forming: all the node stuff is
	{						// managed behind the scenes. We merely input a value.
											// What happens when "[1, 2, 4].append(8)":
											// s1<-->2<-->4<-->e
		end->value = element;				// s1<-->2<-->4<-->e8
		end->successor = new LLNode<T>();   // s1<-->2<-->4<-->e8 -->
		end->successor->predecessor = end;	// s1<-->2<-->4<-->e8<-->
		end = end->successor;				// s1<-->2<-->4<--> 8<-->e
	}
	~LinkedList()
	{
		for(LLNode<T>* i = start; i != end; )	// could use iterator, but this is easier,
		{										//
			LLNode<T>* next = i->successor;		// since an iterator won't let you
			delete i;							// delete before
			i = next;							// incrementing.
		}
		delete end;
	}

	void append(LinkedList& LL) // to save time, appending a whole list does NOT copy it.
	{							// so if we later delete LL, end will still be LL.end!
		end->successor = LL.start;
		LL.start->predecessor = end;
		end = LL.end;
	}
};
#endif
