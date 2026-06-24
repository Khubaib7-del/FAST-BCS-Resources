#include<iostream>
using namespace std;
class node{
private:
int obj;
node* nextNode;
public:
node()
{obj=0;
this->nextNode=NULL;
}
node(int obj,node* nextNode=NULL)
{
this->obj=obj;	
this->nextNode=nextNode;	
}
int get()
{return obj;
}
void set(int obj)
{this->obj=obj;
}
node* getNext()
{return this->nextNode;
}
void setNext(node* nextNode)
{this->nextNode=nextNode;
}
};
class List{
private:
node* head;
node* current;
node* prev;	
int size;	
public:
List();	
void add(int obj);
int get();
bool next();
bool find(int obj);
friend void traverse(List list);
friend List addNode();
bool remove();
};
List::List()
{
head=new node();	
current=NULL;
prev=NULL;
size=0;	
}
void List::add(int obj)
{node* newNode=new node(obj);
if(size==0)
{
head->setNext(newNode);
current=newNode;
prev=head;		
}else
{newNode->setNext(current->getNext());
current->setNext(newNode);
prev=current;
current=newNode; //current=current->getNext();
}
size++;
}
int List::get()
{if (current!=NULL)
return current->get();
}
bool List::next()
{
if(current==NULL) return false;	
prev=current;
current=current->getNext();
return (current!=NULL);
}
bool List::find(int obj)
{
if(size==0)	{
return false;}else
{
	node* tempCurr=current;
	node* tempPrev=prev;
	current=head;
	for(int i=1;this->next();i++)
	{if(obj==current->get())
	return true;
	}
	current=tempCurr;
	prev=tempPrev;
	return false;
}}
/*bool List::remove()
{if(current==NULL)return false;
else
{node* temp=head;
while(temp->getNext()!=prev)
{temp=temp->getNext();
}
prev->setNext(current->getNext());
delete current;
current=prev;
prev=temp;
}
size--;
return true;
}*/
bool List::remove() {
    if (current == NULL || current == head) {
        return false;
    }
 prev->setNext(current->getNext());
    delete current;
    current = prev;

    node* temp = head;
    if (prev != head) {
        while (temp->getNext() != prev && temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        prev = temp;
    } else {
        prev = head;
    }

    size--;
    return true;
}


void traverse(List list)
{node* tempCurr=list.current;
node* tempPrev=list.prev;
list.current=list.head;
for(int i=1;list.next();i++)
{cout<<"\n Element: "<<i<<" "<<list.get();
}
list.current=tempCurr;
list.prev=tempPrev;
}
List addNode()
{List list;
list.add(6);
list.add(10);
list.add(2);
list.add(1);
list.add(3);
cout<<"\n The size of the list is: "<<list.size<<endl;
return list;	}	

int main()
{List list=addNode();
traverse(list);
if(list.find(1))
cout<<"\n Number found"<<endl;
else
cout<<"Number not found"<<endl;
list.remove();
traverse(list);
return 0;}