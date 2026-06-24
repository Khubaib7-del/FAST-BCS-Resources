#include<iostream>
#include<stdlib.h>
#include "TreeNode.cpp";
using namespace std;
void insert(TreeNode<int>* root,int *info){
TreeNode<int>*	newNode=new TreeNode<int>(info);

TreeNode<int> *p,*q;
p=q=root;
while(*info !=*(p->getInfo())&& q!=NULL)
{
p=q;
if(*info <*(p->getInfo()))
q=p->getLeft();
else
q=p->getRight();	
}

if(*info==*(p->getInfo()))
{cout<<"attempt to insert duplicate "<<*info<<endl;
delete newNode;
}
else if(*info<*(p->getInfo()))
p->setLeft(newNode);
else 
p->setRight(newNode);

}
main()
{
int x[]={14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5,-1};
TreeNode<int>*	root=new TreeNode<int>();
root->setInfo(&x[0]);
for(int i=1;x[i]>0;i++)
{insert(root,&x[i]);
}	
}