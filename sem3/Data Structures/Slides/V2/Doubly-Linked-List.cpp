# include<iostream>
using namespace std;
template <typename T>
class Node{
private:
T object;
Node *nextNode;
node *prevNode;
public:
T get()
{return object;
	}	
void set(const T&obj)
{object=obj;
	}
Node* getNext()
{return nextNode;
		}		
void setNext(Node *nextNode)
{this->nextNode=nextNode;
}
Node* getPrev()
{return prevNode;
		}		
void setPrev(Node *prevNode)
{this->prevNode =prevNode;
}

Node(const T&obj,Node *next=NULL,Node *prev=NULL)
{object=obj;
this->nextNode=next;
this->prevNode=prev;
}
Node()
{this->nextNode=NULL;
 this->prevNode=NULL;
}
};
template <typename T>
class List{
private:	
Node<T>* head;	
Node<T>* tail;	
int size;	
public:
List()
{head=tail=new Node<T>();
size=0;
}
void insertAtHead(const T&obj)
{Node<T> *newNode=new Node<T>(obj,head->getNext());
if(size==0)
{newNode->setPrev(head);
head->setNext(newNode);
tail=newNode;
}else{
(head->getNext())->setPrev(newNode);
newNode->setPrev(head);
head->setNext(newNode);
}
size++;	
	
}
void insertAtTail(const T&obj)
{
Node<T> *newNode=new Node<T>(obj);	
tail->setNext(newNode);
newNode->setPrev(tail);
tail=newNode;	
size++;
}
void insertInorder(const T&obj)
{
	if(size==0)
	{insertAtHead(obj);
	}else if(obj<=(head->getNext())->get())
	{insertAtHead(obj);
	}else if(obj>=tail->get())
	{insertAtTail(obj);
	}else
	{
		Node<T> *newNode=new Node<T>(obj,NULL);
		Node<T> *current=head->getNext();
		//There is no need for prev pointer
		//Node<T> *prev=head;
		while(current!=NULL&& obj>=current->get())
		{//prev=current;
		current=current->getNext();
		}
		newNode->setNext(current);
		(current->getPrev())->setNext(newNode);
		newNode->setPrev(current->getPrev());
		current->setPrev(newNode);
		
size++;		
	}
	
	
}
//Write remove methods for doubly linked list.
int main()
{

return 0;
}