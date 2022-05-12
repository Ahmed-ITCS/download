#include<iostream>
using namespace std;

template<typename t>
class node{
private:
	t data;
	int key;
	node* next;
public:
	node()
	{
		next = nullptr;
	}
	node(int k, int d)
	{
		data = d;
		key = k;
		next = nullptr;
	}
	void setkey(int k)
	{
		key = k;
	}
	void setdata(int d)
	{
		data = d;
	}
	void setnext(node* n)
	{
		next = n;
	}
	t getdata()
	{
		return data;
	}
	int getkey()
	{
		return key;
	}
	node* getnext()
	{
		return next;
	}
};

template<typename tt>
class cll{
private:
	node<tt>* head;
public:
	cll(node<tt>* n)
	{
		head = n;
		head->setnext(head);
	}
	node<tt>* exist(int k)
	{
		node<tt>* temp = head;
		while (temp->getnext() != head)
		{
			if (temp->getkey() == k)
			{
				return temp;
			}
			temp = temp->getnext();
		}
		return 0;
	}
	void append(node<tt>* n)
	{
		if (exist(n->getkey()))
		{
			cout << "already in there bro\n";
		}
		else
		{
			if (head == nullptr)
			{
				head = n;
				head->setnext(head);
	}
			else
			{
				node<tt>* temp = head;
				while (temp->getnext() != head)
				{
					temp = temp->getnext();
				}
				temp->setnext(n);
				n->setnext(head);
			}
		}
	}
	void prepend(node<tt>* n)
	{
		if (exist(n->getkey()))
		{
			cout << "already exist\n";
		}
		else		
		{
			if (head == nullptr)
			{
				head = n;
				head->setnext(head);
			}
			else
			{
				node<tt>* temp = head;
				while (temp->getnext() != head)
				{
					temp = temp->getnext();
				}
				n->setnext(head);
				head = n;
				temp->setnext(head);
				
				

			}
		}
	}
	void insert(int k, node<tt>* n)
	{
		if (head == nullptr)
		{
		append(n);
		}
		node<tt>* ptr = exist(k);
		if (ptr)
		{
			n->setnext(ptr->getnext());
			ptr->setnext(n);
		}
		else
		{
			cout << "it doesn't exist\n";
		}
	}
	void deletee(int k)
	{
		if (head->getkey() == k)
		{
			node<tt>* t = head;
			head = head->getnext();
			t = nullptr;
			delete[]t;
		}
		node<tt>* temp = head;
		node<tt>* temp2 = head->getnext();

		while (temp2 != nullptr)
		{
			if (temp2->getkey() == k)
			{
				temp->setnext(temp2->getnext());
				temp2 = nullptr;
				delete[] temp2;

				break;
			}
			temp = temp->getnext();
			temp2 = temp2->getnext();
		}
	}
	void show()
	{
		node<tt>* temp = head;
		while (temp->getnext() != head)
		{
		cout << temp->getkey() << "          " << temp->getdata() << endl;
			temp = temp->getnext();
		}
		cout << temp->getkey() << "          " << temp->getdata() << endl;

		cout << "-------------------\n";
	}
	//ignore this funtion
	/*ll<tt> reverse()
	{
	ll<tt> l;
	node<tt>* temp = head;
	node<tt>* temp2 = head->getnext();
	while (head != nullptr)
	{
	if (temp2->getnext() == nullptr)
	{
	l.append(temp2);
	temp->setnext(nullptr);
	temp2 == nullptr;
	temp2 = head->getnext();
	temp = head;
	if (head->getnext() == nullptr)
	{
	l.append(head);
	head == nullptr;
	}

	}
	else
	{
	cout << "6/\n";
	temp2 = temp2->getnext();
	temp = temp->getnext();
	}
	if (head == nullptr)
	{
	break;
	}
	}
	return l;
	}*/
};



int main()
{
	node<int>* n1 = new node<int>(1, 10);
	node<int>* n2 = new node<int>(2, 20);
	node<int>* n3 = new node<int>(3, 30);
	node<int>* n4 = new node<int>(4, 40);
	cll<int> l(n1);
	l.prepend(n2);
	l.insert(1, n3);
	l.show();
	l.deletee(1);
	l.append(n1);
	l.prepend(n4);
	l.deletee(1);
	l.deletee(4);
	l.prepend(n1);
	l.append(n4);
	l.show();
	
	system("pause");
}
