#include<queue>
#include<iostream>
#include<exception>

using namespace std;
template <typename T> 
class Stack {
  public:
    Stack(); // constructor.
    void push(const T& data); // push operation.
    T pop(); // return the value in the top and pop it out of the stack.
    T top(); // return the value in top.
    int size() const{return count;}  // return size of the stack.
    bool empty(){return q1.empty();} // check whether is empty.

  private:
    queue<T> q1; // two queues.
    queue<T> q2;
    int count; // the number of elements.
};
template <typename T>
Stack<T>::Stack()
{
	count=0;
}
template <typename T>
void Stack<T>::push(const T& data)
{
	q1.push(data);
	count++;
}
template <typename T>
T Stack<T>::pop()
{
    T a;
    if (count==0) return a;
    a = q1.back();
    while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
    q1.pop();
    while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    count--;
    return a;
}
template <typename T>
T Stack<T>::top()
{
	return q1.back();
}
template <typename T>
void print(Stack<T>& a)
{
    Stack<T> tmp;
    while(!a.empty())
        {
            std::cout<<a.top()<<" ";
            tmp.push(a.pop());
        }
    std::cout<<std::endl;
    while(!tmp.empty())
        a.push(tmp.pop());
}