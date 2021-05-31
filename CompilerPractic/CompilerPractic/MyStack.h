#ifndef MPS
#define MPS
#include<iostream>
template <class T>
struct Node
{
	T info;
	Node*next;
};
template <class T>
class MyStack
{
	Node<T>* head;
public:
	MyStack()
	{
		head = NULL;
	}
	Node<T>*gethead()
	{
		return head;
	}
	bool operator!()
	{
		return !head;
	}
	void clean()
	{
		Node<T>*del = head;
		while (head)
		{
			del = head;
			head = head->next;
			delete del;
		}
	}
	void push(T value)
	{
		Node<T>*v = new Node<T>;
		v->info = value;
		Node<T>*cur = head;
		head = v;
		head->next = cur;
	}
	bool pop(int n)
	{
		Node<T>*cur;
		while (head&&n--)
		{
			cur = head;
			head = head->next;
			delete cur;
		}
		if (n>0)
			return 0;
		return 1;
	}
	T pop()
	{
		if (!head)
			throw 0;
		T value = head->info;
		Node<T>*cur = head;
		head = head->next;
		delete cur;
		return value;
	}
	T top()
	{
		if (!head)
			throw 0;
		return head->info;
	}
	void replace(int depth, T value)
	{
		Node<T>* cur = head;
		while (cur&&depth--)
			cur = cur->next;
		if (depth<0&&cur)
			cur->info = value;
	}
	MyStack(MyStack<T>&q)
	{
		head = NULL;
		Node<T>*c = q.head;
		while (c)
		{
			this->push(c->info);
			c = c->next;
		}
	}
	~MyStack()
	{
		this->clean();
	}
	bool operator==(MyStack<T>&a)
	{
		Node<T>*c1 = head;
		Node<T>*c2 = a.head;
		while (c1&&c2)
		{
			if (c1->info != c2->info)
				return 0;
			c1 = c1->next;
			c2 = c2->next;
		}
		if (!c1&&c2 || c1&&!c2)
			return 0;
		return 1;
	}
	bool operator!=(MyStack<T>&a)
	{
		Node<T>*c1 = head, *c2 = a.head;
		while (c1&&c2)
		{
			if (c1->info != c2->info)
				return 1;
			c1 = c1->next;
			c2 = c2->next;
		}
		if (!c1&&c2 || c1&&!c2)
			return 1;
		return 0;
	}
	MyStack<T>& operator=(MyStack&a)
	{
		Node<T>*c1 = q->head, *c2 = head;
		while (c1&&c2)
		{
			c2->info = c1->info;
			c1 = c1->next;
			c2 = c2->next;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, MyStack<T>& q)
	{
		Node<T>*cur = q.head;
		while (cur)
		{
			out << cur->info << " ";
			cur = cur->next;
		}
		out << std::endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, MyStack<T>& q)
	{
		T t;
		in >> t;
		q.push(t);
		return in;
	}
};
#endif MPS