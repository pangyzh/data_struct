 #include"RHTree.hpp"
#include<iostream>
using namespace std;
void my_delete(node * tmp)
{
    if (tmp->left!=NULL) 
      my_delete(tmp->left);
    if (tmp->right!=NULL) 
      my_delete(tmp->right);
  	delete tmp;
}

node * my_Find(node *tmp,int value)
{
    if (tmp->ele<value)
    {
        if (tmp->right->ele==value) 
          return tmp;
        return my_Find(tmp->right, value);
    }
    if (tmp->left->ele==value) return tmp;
    return my_Find(tmp->left, value);
}
RHTree::~RHTree()
{
  	if (root!=NULL) 
    	my_delete(root);
  	root=NULL;			
}


void RHTree::insert(int x)
{
node** flag=&root;
  while(*flag!=NULL)
    flag=(x<=(*flag)->ele)?&((*flag)->left):&((*flag)->right);
  *flag=new node(x);
}
void RHTree::preOrder(node* r)
{
	if(r==NULL) return ;
	cout<<" "<<r->ele;
	preOrder(r->left);
	preOrder(r->right);
}
void RHTree::postOrder(node* r)
{
	if(r==NULL) {return ;}
	postOrder(r->left);
	postOrder(r->right);	
	cout<<" "<<r->ele;
	
}

void RHTree::inOrder(node* r)
{
	if(r==NULL) return ;
	inOrder(r->left);	
	cout<<" "<<r->ele;
	inOrder(r->right);	
}
