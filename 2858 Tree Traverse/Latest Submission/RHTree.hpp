#ifndef RHTREE_HPP
#define RHTREE_HPP
#include<iostream>
using namespace std;
struct node {
  int ele;
  node* left;
  node* right;
  node(int e):left(0), right(0){
    ele = e;
  }
};

class RHTree{
	public:
		RHTree(){root=NULL;}
		~RHTree();
		void insert(int ele);
		void inOrder(node* );
		void preOrder(node* );
		void postOrder(node* );
		node* getRoot()const{return root;}
	private:
		node* root; 
};
#endif