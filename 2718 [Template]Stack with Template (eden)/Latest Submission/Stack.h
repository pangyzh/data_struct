 #include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
template<typename T>
class Stack {  
    public:  
        Stack(){
          top_node=NULL;
          node_num=0;
        }

        Stack(const Stack &stack){
            top_node = NULL;
            node_num = 0;
          Node* temp=stack.top_node;
          int Num=stack.node_num;
          T arr[Num];
          for(int i = 0; i < Num;i++){
            arr[Num-i-1]=temp->element;
            temp=temp->next;
          }
          for(int i = 0; i < Num; i++){
            push(arr[i]);
          }
        }

        ~Stack(){
          clear();
        }

        bool empty(){
          return node_num==0;
        }

        int size() const{
          return node_num;
        }

        T top() const{
          return top_node->element;
        }

        void push(T element){
          if(top_node==NULL)
          {
            top_node=new Node(element);
            node_num++;
          }
          else{
            Node* current=new Node(element);
            current->next=top_node;
            top_node=current;
            node_num++;
          }
        }

        void pop(){
          if(!empty()){
            Node* temp=top_node;
            top_node=top_node->next;
            delete temp;
            node_num--;
          }
        }

        void swap(Stack& stack){
          Node*temp=top_node;
          top_node=stack.top_node;
          stack.top_node=temp;
        }

        void reverse() /*reverse the elements' order in the stack*/			{
          int n=node_num;
          T arr[n];
          for(int i = 0;i<n;i++){
            arr[i]=top();
            pop();
          }
          for(int j = 0; j < n ; j++){
            push(arr[j]);
          }
        }

        void clear(){
          while(node_num!=0){
            pop();
          }
        }

    private:  
        struct Node {  
            T element;  
            Node* next;  
            Node(T ele, Node *n = NULL) {  
                element = ele;  
                next = n;  
            }  
        };  
        Node *top_node;  
        int node_num;  
};