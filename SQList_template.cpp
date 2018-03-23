#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node *nextptr;
};

class List
{
public:
	List();
	void CreatList(int *datas, int length);
	bool ListEmpty();
	void ClearList();
	bool GetElem(int location, int &element);
	bool LocateElem(int &location, int element);
	bool ListInsert(int location, int element);
	bool ListDelete(int location);
	int ListLength();
	void ListPrint();

private:
	Node *p;
};


void List::ListPrint()
{
	Node *m;
	Node *n;
	m = p;
	for (int i = 0; i < p->data; i++)
	{
		n = m->nextptr;
		cout << "The List number in " << i+1 << " is:"<< n->data << endl;
		m = n;
	}
}

List::List()
{
	p = new Node;
	p->nextptr = NULL;
	p->data = 0;
}

void List::CreatList(int *datas, int length)
{
	p->data = length;
	Node *m;
	m = p;
	for (int i = 0; i < length; i++)
	{
		Node *n = new Node;
		n->data = datas[i];
		m->nextptr = n;
		m = n;
	}
	m->nextptr = NULL;
	m = nullptr;
}

bool List::ListEmpty()
{
	if((p->data == 0) && (p->nextptr == NULL) )
	{
		return true;
	}
	return false;
}

void List::ClearList()
{
	Node *m;
	Node *n;
	m = p->nextptr;
	while(m != NULL)
	{
		n = m->nextptr;
		delete m;
		m = n;
	}
	p->data = 0;
	p->nextptr = NULL;
}

bool List::GetElem(int location, int &element)
{
	if(location > p->data)
	{
		return false;
	}
	Node *q;
	q = p;
	for (int i = 0; i < location; i++)
	{
		q = q->nextptr;
	}
	element = q->data;
	return true;
}

bool List::LocateElem(int &location, int element)
{
	Node *q = p->nextptr;
	int searchLocation = 0;
	while (q != NULL)
	{
		searchLocation += 1;
		if(q->data == element)	break;
		q = q->nextptr;
	}
	if (q == NULL)
	{
		return false;
	}
	location = searchLocation;
	return true;
}

bool List::ListInsert(int location, int element)
{
	if (location > (p->data +1))
	{
		return false;
	}
	Node *m;
	Node *n = new Node;
	m = p;
	for (int i = 0; i < (location-1); i++)
	{
		m = m->nextptr;
	}
	if(location < (p->data + 1))
	{
		n->data = element;
		n->nextptr = m->nextptr;
		m->nextptr = n;
	}
	else
	{
		n->data = element;
		n->nextptr = NULL;
		m->nextptr = n;
	}
	p->data += 1;
	return true;

}

bool List::ListDelete(int location)
{
	if(location > p->data)
	{
		return false;
	}
	Node *m;
	Node *n;
	m = p;
	for (int i = 0; i < (location-1); i++)
	{
		m = m->nextptr;
	}
	if(location < p->data)
	{
		n = m->nextptr;
		m->nextptr = m->nextptr->nextptr;
		delete n;
	}
	else
	{
		n = m->nextptr;
		m->nextptr = NULL;
		delete n;
	}
	p->data -= 1;
	return true;

}

int List::ListLength()
{
	return p->data;
}

int main()
{
	List mylist;

	int myLength = 0;
	cout << "Please input the List length" <<endl;

	cin >> myLength;
	int *myData = new int[myLength];
	cout << "Please input the data " << endl;
	for(int i = 0; i < myLength; i++ )
	{
		cin>>myData[i];
	}

	mylist.CreatList(myData,myLength);
	mylist.ListPrint();

	
}

