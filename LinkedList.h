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
	LLIterator(LinkedList<T>& LL): node(LL.start) {}
	bool can_continue() {
		return node->successor != NULL;
	}
	bool can_regress() {return node->predecessor != NULL;}
	void next() {node = node->successor;}
	void prev() {node = node->predecessor;}
	T& value() {return node->value;}
};

template<typename T>
class LinkedList
{
public:
	template<typename T>
	friend class LLIterator;
	LLNode<T>* start;		// half-open: [start, end); in particular,
	LLNode<T>* end;			// end doesn't contain anything itself, and 
							// end->successor == NULL.

public:
	LinkedList(): end(new LLNode<T>) {start = end;}	// or could do "start(new LLNode<T>), end(start)",
													// but this way jives with phrasing in "append".
	LinkedList(const LinkedList<T>& other): start(other.start), end(other.end) {cout << "bei";}

	void append(T element)	// don't worry about loops forming: all the node stuff is
	{						// managed behind the scenes. We merely input a value.
											// What happens when "[1, 2, 4].append(8)":
											// s1<-->2<-->4<-->e
		end->value = element;				// s1<-->2<-->4<-->e8
		end->successor = new LLNode<T>;		// s1<-->2<-->4<-->e8 -->
		end->successor->predecessor = end;	// s1<-->2<-->4<-->e8<-->
		end = end->successor;				// s1<-->2<-->4<--> 8<-->e
	}
	~LinkedList()
	{
		for(LLNode<T>* i = start; i != NULL; )	// could use iterator, but this is easier,
		{										// <-- i5<--> 6<-->...	//
			LLNode<T>* next = i->successor;		// <-- i5<-->n6<-->...	// since an iterator won't let you
			delete i;							//       <-- n6<-->...	// delete before
			i = next;							//       <-- i6<-->...	// incrementing.
		}
	}

	inline bool is_empty() {return start==end;}

	void join(LinkedList& LL)	// Sets both (*this) and LL to concatenated list.
	{							// to save time, does NOT copy LL.
								// However, problem: if L.join(Y), then after L destroyed, destruction of Y raises error.
		if(is_empty()) (*this) = LL;		// need to check for empty cases.
		else if(LL.is_empty()) LL = *this;	// ` ` ` ` ` `
		else											// What happens when "[1, 2, 4].append([3, 5])"?
		{												//  s1<-->2<-->4<-->e
														//               S3<-->5<-->E
			
			end->predecessor->successor = LL.start;		//  s1<-->2<-->4<-- e
			LL.start->predecessor = end->predecessor;	//             ^
														//              \
														//               v
														//               S3<-->5<-->E

			delete end;	end = LL.end;					//  sS1<-->2<-->4
						LL.start = start;				//              ^
														//               \
														//                v
														//                 3<-->5<-->eE
		}
	}
	void append(LinkedList& LL)	// copies LL
	{
		for(LLIterator<int> i(LL); i.can_continue(); i.next())
		{
			append(i.value());
		}
	}
};
#endif
