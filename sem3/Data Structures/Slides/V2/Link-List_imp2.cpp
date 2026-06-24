# include<iostream>
using namespace std;
template <typename T>
class Node{
private:
T object;
Node *nextNode;
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
Node(const T&obj,Node *next=NULL)
{object=obj;
this->nextNode=next;
}
Node()
{this->nextNode=NULL;
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
{
Node<T> *newNode;

head->setNext(newNode=new Node<T>(obj,head->getNext()));
	if(size==0)
	{tail=newNode;
	}
size++;	
	
}
void insertAtTail(const T&obj)
{
Node<T> *newNode=new Node<T>(obj,NULL);	
tail->setNext(newNode);
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
		Node<T> *lastCurrent=head;
		while(current!=NULL&& obj>=current->get())
		{lastCurrent=current;
		current=current->getNext();
		}
		lastCurrent->setNext(newNode);
		newNode->setNext(current);
size++;		
	}
	
	
}
void removeAtHead()
{if(size==0)
return;
else
{ Node<T> *temp=head->getNext();
if(temp->getNext()==NULL)
{tail=head;
}
head->setNext(temp->getNext());
delete temp;
}
size--;
}
void removeAtTail()
{if(size==0)
return;
else{
Node<T> *temp=head;
while(temp!=NULL&& temp->getNext()!=tail)
{temp=temp->getNext();
	}	
delete tail;
tail=temp;	
}
size--;
}
void removeInOrder(const T&obj)
{if (size==0) return;
else if(obj==head->getNext()->get())
      removeAtHead(obj);
else if(obj==tail->get())
      removeAtTail(obj);
else
{ node<T>* current=head->getNext();
  node<T>* prev=head;
  while(current!=NULL&&obj==current->get())
  {prev=current;
  current=current->getNext();
  }
  prev->setNext(current->getNext());
  if(current==tail)
    tail=prev;
  delete current;
  size--;
}
}
};

int main()
{

return 0;
}