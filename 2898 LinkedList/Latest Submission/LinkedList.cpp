#include<iostream>
#include"LinkedList.hpp"
using namespace std;
LinkedList::LinkedList()
{
  head=NULL;
  tail=NULL;
  _size=0;
}

LinkedList::~LinkedList()
{
  clear();
}
void LinkedList::add(E e)
{
  if(_size==0)
  {
    head=tail=new node(e);
    _size++;
    return;
  }
  if(_size==1)
  {
    tail=new node(e,NULL,head);
    head->next = tail;    
    _size++;
    return;
  }
  tail->next=new node(e,NULL,tail);
  tail=tail->next;
  _size++;
  return;
}

void LinkedList::remove(E e)
{
  if(!contain(e)) return ;
  node* temp=head;
  while(temp!=NULL)
  {
    if(temp->data==e)
    {
      if(_size==1)
        {
          delete head;
          head=NULL;
          _size--;
          return;
        }
        if (temp==head)
        {
              head = head->next;
                head->prev = NULL;
                if (_size==2) tail = head;
                delete temp;
                _size--;
                temp = head;
        }
        else if (temp==tail)
            {
                tail->prev->next = NULL;
                tail = tail->prev;
                delete temp;
                _size--;
                return ;
            }
        else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                node * p = temp;
                temp = temp->next;
                _size--;
                delete p;
            }
        }
        else temp = temp->next;
    }        
}

void LinkedList::clear()
{
  if(_size==0)return ;
  if(_size==1){
    delete head;
    head=tail=NULL;
    _size=0;
    return;
  }
  while(head!=NULL)
  {
        node * temp = head;
        head = head->next;
        delete temp;    
  }

    head = tail = NULL;
    _size = 0;
}

bool LinkedList::contain(E e)
{
  node* temp=head;
    while (temp!=NULL)
    {
        if (temp->data==e) return 1;
        temp = temp->next;
    }
    return 0;  
}

bool LinkedList::isEmpty(){return _size==0;}
int LinkedList::size(){return _size;}
E& LinkedList::operator[](int index)
{
  return get(index);
}
E& LinkedList::get(int index)
{
  node * temp=head;
  for(int i=0;i<index;i++)
  {
    temp=temp->next;
  }
  return temp->data;
}

int LinkedList::indexOf(E element)
{
  node* temp=head;
  int index=0;
  while(temp!=NULL)
  {

    if(temp->data==element) return index;
    temp=temp->next;
    index++;
  }
  return -1;
}

