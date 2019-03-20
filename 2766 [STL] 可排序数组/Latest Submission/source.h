#include <iostream>
#include <string>
#include<list>
#include<algorithm>
using namespace std;


template<typename T>
class SortableArray
{
public:
	SortableArray(){size_=0;}
	SortableArray(int size){maxsize=size;}
	~SortableArray(){}
	void pushBack(T ele);
	void sort();
	void printArray()
	{
		typename list<T>::const_iterator iter = arr.begin();  
        while (iter != arr.end())  
        {  
            cout << *iter++ << " ";  
        }  
        cout << endl; 
	}
private:
	int size_;
	list<T> arr;
	int maxsize;
};

	template<typename T>
	void SortableArray<T>::pushBack(T ele)
	{
		arr.push_back(ele);
		size_++;
	}
	template<typename T>
	void SortableArray<T>::sort()
	{
		arr.sort();
	}
