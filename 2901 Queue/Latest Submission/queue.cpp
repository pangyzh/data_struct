 #include"queue.hpp"
#include<iostream>
using namespace std;
queue::queue()
{
	max_size=0;
	storage=NULL;
	head=0;
	rear=0;
}

queue::~queue()
{
	delete [] storage;
	max_size=0;
}

void queue::push(E ele)
{
	if(isFull())
	return ;
	int arr[20]={0};
	if(max_size!=0){
		for(int i = 0; i < max_size; i++){
			arr[i]=storage[i];
		}
		delete[]storage;
	}
	arr[max_size]=ele;	
	max_size++;
	
	storage=new E[max_size];
	for(int i = 0; i < max_size; i++)
	{
		storage[i]=arr[i];
	}
	head=storage[0];
	rear=ele;
}
void queue::pop()
{
	if(isEmpty())
	return ;
	int arr[20]={0};

	for(int i = 0; i < max_size-1; i++)
	{
		arr[i]=storage[i+1];
	}
	delete[]storage;
	storage=NULL;
	max_size--;
	storage=new E[max_size];
	for(int i = 0; i < max_size; i++)
	{
		storage[i]=arr[i];
	}
	head=arr[0];
	rear=arr[max_size-1];
}
E queue::front()
{
	return head;
}
E queue::back()
{
	return rear;
}

bool queue::isEmpty()
{
	return max_size==0;
}

bool queue::isFull()
{
	return max_size>MAX_SIZE||MAX_SIZE==max_size;
} 

void queue::clear()
{
	delete[]storage;
	storage=NULL;
	max_size=0;
	head=0;
	rear=0;
}