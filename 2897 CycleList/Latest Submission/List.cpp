#include<iostream>
#include"List.hpp"
#include<vector>

using namespace std;


CycleList::CycleList(const vector<string> &other)
{
	_size=other.size();
	if(_size==0)return;
	head=new node(*other.begin());
	node * temp = head;
	for(vector<string>::const_iterator it=other.begin()+1;it!=other.end();it++)
	{
		temp->next=new node(*it,0,temp);
		temp=temp->next;
	}
	temp->next=head;
	head->front=temp;
}
CycleList::~CycleList()
{
	clear();
}
int CycleList::size()const
{
	return _size;
}
void CycleList::Eat(int pos)
{
   if (_size==0||pos>_size-1||pos<0) return ;
    node * temp = head;
    for (int n = 0;n<pos;n++) temp = temp->next;
    if (_size>3)
    {
        node * now = temp,* nex = temp->next, * fro = temp->front;
        temp->front->front->next = temp->next->next;
        temp->next->next->front = temp->front->front;
        if (now==head||nex==head||fro==head) head = nex->next;
        delete now;
        delete nex;
        delete fro;
        _size-=3;
    }
    else
    {
        head->front->next = NULL;
        while(head!=NULL)
        {
            node * temp = head;
            head = head->next;
            delete temp;
        }
        _size = 0;
    }
	
}
void CycleList::clear()
{
    if (head==NULL) 
	return ;
    head->front->next = NULL;
    while(head!=NULL)
    {
        node * temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    _size  = 0;	
}

void CycleList::Eat()// remove head, head->front,head->next
{
    if (_size==0) return ;
    if (_size>3)
    {
        node *now = head,* nex = head->next, * fro = head->front;
        head->front->front->next = head->next->next;
        head->next->next->front = head->front->front;
        head = head->next->next;
        delete now;
        delete nex;
        delete fro;
        _size-=3;
    }
    else
    {
        head->front->next = NULL;
        while(head!=NULL)
        {
            node * temp = head;
            head = head->next;
            delete temp;
        }
        _size = 0;
    }
}

ostream& operator<<(ostream & os , const CycleList & other)
{
    CycleList::node * temp = other.head;
    if (other.size()==0) return os;
    do
    {
        os<<temp->food<<' ';
        temp = temp->next;
    }while (temp!=other.head);
    return os;
}