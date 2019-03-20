 #include <iostream>
#include <string.h>


using namespace std ;


template<class T >
class Set
{
public:
 	Set() {maxSize=0;data=NULL;count=0;}
 	Set( int maxsize ) {maxSize=maxsize;data=new T[maxSize];count=0;}
 	~Set() {delete [] data;count=0;}
 	Set( const Set& s) {count=s.count;maxSize=s.maxSize;data=new T[maxSize];for(int i=0;i<count;i++)data[i]=s.data[i];}
 	Set operator+( const Set& s ) ;
 	Set operator-( const Set& s ) ;
 	void operator=( const Set& s ) ;
 	bool insert( T newItem ) ;
 	bool erase( T targetItem ) ;
 	void print() const {
	 	for(int i = 0; i < count; i++){
 			if(i!=count-1)
			 cout<<data[i]<<' ';
			 else
			 cout<<data[i]<<' '<<endl;
	 	}
	}
	bool isInSet(T e);
 	T* getData() const {return data;}
 	int getCount() const {return count;}
 	int getMaxSize() const{return maxSize;} 
private:
 	int count ;
 	int maxSize ;
 	T* data ;
} ;
template< class T >
void Set<T>::operator=(const Set<T>& s)
{
	maxSize=s.maxSize;
  count=s.count;
	data=new T[maxSize];
	for(int i = 0; i < count; i++)
	{
		data[i]=s.data[i];
	}
}
template< class T >
bool Set<T>::isInSet(T e){//
	for(int i = 0; i < count; i++){
		if(data[i] == e)
		return 1;
	}
	return 0;
}

template< class T >
bool Set<T>::insert(T e){//
	if(isInSet(e))
	return 0;
	data[count] = e;
  	count++;
	return 1;
	
}
template< class T >
bool Set<T>::erase(T e){
	if(isInSet(e)){
		for(int i = 0; i < count; i++){
		if(data[i] == e){
			for(int j = i; j < count; j++){
				data[j] =data[j+1];
			}
			count--;
			return 1;
		}
	}
	}
	return 0;	
}
template< class T >
Set<T> Set<T>::operator-(const Set<T>& s)
{
	Set answer(maxSize+s.maxSize);
	for(int i = 0; i < count; i++)
	answer.insert(data[i]);
	for(int m = 0; m < s.count; m++)
	{
		if(isInSet(s.data[m]))
			answer.erase(s.data[m]);	
	}
	return Set<T>(answer);
	
}
template< class T >
Set<T> Set<T>::operator+(const Set<T>& s)
{
	Set answer(maxSize+s.maxSize);
	for(int i = 0; i < count+s.count; i++)
	{
		if(i<count)
		answer.insert(data[i]);
		if(i>=count)
		answer.insert(s.data[i-count]); 
	}
	/*for(int j = 0; j < s.count; j++)
	if(isInSet(s.data[j]))
	answer.erase(s.data[j]);*/
	return Set<T>(answer);
}
	
	