#include<stdlib.h>
using namespace std;
template <class T>
class TreeNode{
private:
T *object;
TreeNode *left;
TreeNode *right;

public:
TreeNode()
{this->object=NULL;
this->left=NULL;
this->right=NULL;
	}		
TreeNode(T *object)
{this->object=object;
this->left=NULL;
this->right=NULL;
	}	
const T *getInfo()
{return this->object;
	}	
void setInfo(T *object)
{this->object=object;
	}	
TreeNode* getLeft()
{return left;
	}	
	
void setLeft(TreeNode* left)
{this->left=left;
	}	
TreeNode* getRight()
{return right;
	}	
	
void setRight(TreeNode* right)
{this->right=right;
	}	
int isLeaf()
{if(this->left==NULL && this->right==NULL)
	{
	return 1;}
return 0;		}		
};