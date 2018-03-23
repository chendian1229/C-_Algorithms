#include <iostream>
using namespace std;

//定义结点
struct Node
{
	int data;
	Node *nextptr;
};
//定义单链表类
class chainList
{
public:
	void InitList();//初始化一个空表
	void CreatList(int *datas, int length);//创建长度为length的链表，数据通过数组指定，这里采用尾插法
	bool ListEmpty();//判断是否为空表
	void ClearList();//清空表
	bool GetElem(int location, int &element);//获取元素
	bool LocateElem(int &location,int element);//查找相等元素的索引位置
	bool ListInsert(int location, int element);//插入元素
	bool ListDelete(int location, int &element);//删除元素
	int ListLength();//返回表的长度
private:
	Node *p;//头结点
};

//实现类 chainList 中各成员函数
void chainList::InitList()
{
	p = new Node;//给指针分配内存
	p->nextptr=NULL;
	p->data=0;
}

void chainList::CreatList(int *datas, int length)
{
	p->data = length;//头结点中的数据存储表长
	Node *m;
	m = p;
	for (int i = 0; i < length; i++)
	{
		Node *n = new Node;
		n->data = datas[i];
		m->nextptr = n;
		m = n;//m->nextptr;
	}
	m->nextptr = NULL;
	m = nullptr;
}

bool chainList::ListEmpty()
{
	if ((p->data == 0) && (p->nextptr == NULL))
	{
		return true;
	}
	return false;
}

void chainList::ClearList()
{
	Node *m;
	Node *n;
	m = p->nextptr;
	while( m != NULL)
	{
		n = m->nextptr;
		delete m;
		m = n;
	}
	p->nextptr=NULL;//头结点指向的第一个结点清空
	p->data=0;//头结点记录表长度，清零
}

bool chainList::GetElem(int location, int &element)
{
	if (location > p->data)
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

bool chainList::LocateElem(int &location,int element)
{
	Node *q = p->nextptr;
	int searchLocation(0);
	while(q != NULL)
	{
		searchLocation += 1;
		if(q->data == element)
			break;
		q = q->nextptr;
	}
	if (q == NULL)
	{
		return false;
	}
	location = searchLocation;
	return true;
}

bool chainList::ListInsert(int location, int element)
{
	if (location > (p->data + 1))
	{
		return false;
	}
	Node *m;
	Node *n = new Node;
	m = p;
	for (int i=0; i<(location-1); i++)
	{
		m = m->nextptr;
	}
	if (location < (p->data + 1))
	{
		n->data = element;
		n->nextptr = m->nextptr;
		m->nextptr = n;
	}
	else
	{
		n->data = element;
		m->nextptr = n;
		n->nextptr = NULL;
	}
	p->data += 1;
	return true;
}

bool chainList::ListDelete(int location, int &element)
{
	if (location > p->data)
	{
		return false;
	}
	Node *m;
	Node *n;
	m = p;
	for (int i=0; i<(location-1); i++)
	{
		m = m->nextptr;
	}
	if (location < p->data)
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

int chainList::ListLength()
{
	return p->data;
}

int main()
{
	chainList myChainList;
	myChainList.InitList();
	//开始创建链表
	int myLength(0);
	cout<<"想创建多少数据的链表？";
	cin>>myLength;
	int *myDatas = new int[myLength];
	cout<<"请依次输入这"<<myLength<<"个数据，中间以回车符隔开："<<endl;
	for (int i=0; i<myLength; i++)
	{
		cin>>myDatas[i];
	}
	myChainList.CreatList(myDatas,myLength);
	//输出新创建链表中的值
	cout<<"新建链表长度为"<<myChainList.ListLength()<<",表中数据为："<<endl;
	for (int i=0; i<myLength; i++)
	{
		cout<<myDatas[i]<<" ";
	}
	cout<<endl;
	//读取链表中的值
	int readLocation(0);
	int readElement(0);
	cout<<"请输入要读取数据在链表中的位置：";
	cin>>readLocation;
	if (myChainList.GetElem(readLocation,readElement))
	{
		cout<<"链表中第"<<readLocation<<"个数据为："<<readElement<<endl;
	}
	else
		cout<<"链表中无此数据！"<<endl;
	//查找某一元素是否位于链表中
	int findElement(0);
	int findLocation(0);
	cout<<"请输入要查找的元素：";
	cin>>findElement;
	if (myChainList.LocateElem(findLocation,findElement))
	{
		cout<<"找到了元素"<<findElement<<"，其在链表中的索引值为："<<findLocation<<endl;
	}
	else
		cout<<"链表中不存在所需找的值！"<<endl;
	//向链表中插入值
	int insertLocation(0);
	int insertElement(0);
	cout<<"请输入要插入数据的位置：";
	cin>>insertLocation;
	cout<<"请输入要插入的数据的值：";
	cin>>insertElement;
	if (myChainList.ListInsert(insertLocation,insertElement))
	{
		cout<<"插入数据成功！插入后，链表中剩余数据值为："<<endl;
		for (int i = 0; i < myChainList.ListLength();i++)
		{
			int localElement(0);
			myChainList.GetElem(i+1,localElement);
			cout<<localElement<<" ";
		}
		cout<<endl;
	}
	else
		cout<<"数据插入失败！"<<endl;
	//从链表中删除数据
	int deleteLocation(0);
	int deleteElement(0);
	cout<<"请输入要删除数据的索引值：";
	cin>>deleteLocation;
	if (myChainList.ListDelete(deleteLocation,deleteElement))
	{
		cout<<"数据删除成功！删除数据后，链表中剩余数据值为："<<endl;
		for (int i = 0; i < myChainList.ListLength();i++)
		{
			int localElement(0);
			myChainList.GetElem(i+1,localElement);
			cout<<localElement<<" ";
		}
		cout<<endl;
	}
	else
		cout<<"数据删除失败！"<<endl;
	//将链表清空
	myChainList.ClearList();
	//检查链表是否为空
	if (myChainList.ListEmpty())
	{
		cout<<"链表已清空！"<<endl;
	}
	else
		cout<<"链表尚未清空！"<<endl;
}