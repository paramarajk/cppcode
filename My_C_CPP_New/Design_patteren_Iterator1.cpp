#include <memory>
#include <iostream>
using namespace std;

class Iterator
{
public:
	virtual bool next() = 0;
	virtual int get() = 0;
};

class Iterable
{
public:
	virtual unique_ptr<Iterator> iterator() = 0;
};

class Stack : public Iterable
{
	class StackIterator : public Iterator
	{
		Stack *s;
		int index;
	public:
		StackIterator(Stack *s) : s(s)
		{
			index = s->top;
		}

		bool next()
		{
			index--;
			return (index >= 0);
		}

		int get()
		{
			return s->items[index];
		}
	};

	unique_ptr<Iterator> iterator(/* this = &s1 */)
	{
		return unique_ptr<Iterator>(new StackIterator(this));
	}

	int items[10];
	int top;
public:
	Stack() : top(0) { }
	void Push(/* this = &s1 */ int item)
	{
		items[top] = item; // this->items[this->top] = item;
		top++; // this->top++;
	}
	int operator[] (int index)
	{
		return items[index];
	}
};

class NonCopyable
{
private:
	NonCopyable(NonCopyable&) { }
	void operator=(NonCopyable&) { }
public:
	NonCopyable() { }
};

class LinkedList : private NonCopyable//, public Iterable
{
	class LinkedListIterator : public Iterator
	{
		LinkedList *ll;
		//Node *head;
		int item;
	public:
		LinkedListIterator (LinkedList* ll):ll(ll) {

		}
		bool next()
		{
			while (ll->head != nullptr){
				item = ll->head->data;
				return true;
			}
		}

		int get()
		{
			return item;
		}
	};

	unique_ptr<Iterator> iterator()
	{
		return unique_ptr<Iterator>(new LinkedListIterator(this));
	}
private:
	class Node // nested class
	{
	public:
		int data;
		Node *next;
	};
	Node *head, *last;

public:

	//LinkedList(LinkedList&) = delete;
	//LinkedList& operator=(LinkedList&) = delete; 

	LinkedList() : head(nullptr), last(nullptr) { }
	~LinkedList()
	{
		Node *temp = this->head;
		while (temp != nullptr)
		{
			this->head = this->head->next;
			delete temp;
			temp = this->head;
		}
	}
	void Add(/* this = &l1 */ int item)
	{
		Node *n = new Node();
		n->data = item;
		n->next = nullptr;

		if (nullptr == this->head)
			this->head = this->last = n;
		else
		{
			this->last->next = n;
			last = this->last->next;
		}
	}
};


class ListBox
{
public:
	void Display(Iterable *container)
	{
		unique_ptr<Iterator> iterator = container->iterator(); // obtain the iterator object

		cout << "ListBox: ";
		while (iterator->next())
		{
			cout << iterator->get() << " ";
		}
		cout << endl;
	}
};

class ComboBox
{
public:
	void Display(Iterable *container)
	{
		unique_ptr<Iterator> iterator = container->iterator(); // obtain the iterator object

		cout << "ComboBox: ";
		while (iterator->next())
		{
			cout << iterator->get() << " ";
		}
		cout << endl;
	}
};

void main()
{
	Stack s1;
	LinkedList l1;

	s1.Push(10);
	s1.Push(20);
	s1.Push(30);

	l1.Add(10);
	l1.Add(20);
	l1.Add(30);

	ListBox lb;
	lb.Display(&s1);
	//lb.Display(&l1);
}