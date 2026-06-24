# include<iostream>
using namespace std;
template <typename T>
class Node
{
 public:
 T get() { return object; };
 void set(T object) { this->object = object; }; 
 Node * getNext() { return nextNode; };
 void setNext(Node * nextNode) { this->nextNode = nextNode; };
 private:
 T object;
 Node * nextNode;
};
template <typename T>
class queue
{private:
	Node<T> * front,*rear;
	int size;
public:
	queue()
	{front=new Node<T>();
	rear=NULL;
	size=0;
	}
void enqueue(const T& data)
{if(rear!=NULL){

Node<T> *newNode=new Node<T>();
newNode->set(data);
rear->setNext(newNode);
newNode->setNext(NULL);
rear=newNode;
}else
{Node<T> *newNode=new Node<T>();
newNode->set(data);
front->setNext(newNode);
newNode->setNext(NULL);
rear=newNode;
}
size++;
}
T dequeue()
{if(front->getNext()!=NULL){

T x=(front->getNext())->get();
Node<T> *p=front->getNext();
front->setNext(p->getNext());
delete p;
return x;
}
}
};
int main()
{
queue<int> q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(11);
for(int i=0;i<3;i++)
{cout<<q.dequeue()<<endl;
}
return 0;
}