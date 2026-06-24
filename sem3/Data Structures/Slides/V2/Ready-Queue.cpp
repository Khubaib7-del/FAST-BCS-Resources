#include<iostream>
using namespace std;
class Process {
private:
	int pid;
	string name;
public:
	Process(int id=-1, string name="")
	{pid=id;
	this->name=name;
	}
int getPID()
{return pid;
	}	
string getName()
{return name;
}
};
template <typename T>
class queue{
private:
T *A;
int size;
int capacity;
int front,rear;	
int next(int i)	
{return (i+1)%capacity;
	}	
public:
queue(int cap=0)
{
	if(cap>0)
	{A=new T[cap+1];
	 capacity=cap+1;
	 	}else
	{
		A=NULL;
		capacity=0;
	}
	 size=0;
	 rear=front=0;
}
void enqueue(const T&data)
{
	if(capacity==(size+1))
	{
	T *temp=new T[capacity*2];
	int i=next(front);
	for(int j=1;j<=size;j++)	
		{temp[j]=A[i];
		i=next(i);
		}
	delete[] A;
	A=temp;
	front=0;
	rear=size;
	capacity*=2;
	
	rear=next(rear);
	A[rear]=data;	
	}else if(capacity==0)
	{A=new T[2];
	front=0;
	rear=1;
	capacity=2;
	A[rear]=data;
	}else
	{
		rear=next(rear);
		A[rear]=data;
	}
	size++;	
}
T dequeue()
{
if(size==0) return 0;	
else if((size+1)==capacity/2)
{ T *temp=new T[capacity/2];
	int i=next(front);
	for(int j=1;j<=size;j++)	
		{temp[j]=A[i];
		i=next(i);
		}
	delete[] A;
	A=temp;
	front=0;
	rear=size;
	front=next(front);
	T x=A[front];
	capacity/=2;
	size--;
	return x;
	}	
	else
	{front=next(front);
		T x=A[front];
		size--;
		return x;
	}
}
bool isEmpty()
{return (size==0);
}
const T &top()
{return A[next(front)];
}
 void display() {
        if(isEmpty())
        {cout<<"Queue is Empty..."<<endl;
         return;
		}
		cout<<"Ready Queue: ";
		int count=1,i;
		i=next(front);
		while(count<=size)
		{cout<<"[PID: "<<A[i].getPID()<<", Name: "<<A[i].getName()<<" ]";
		count++;
		i=next(i);
		}
		cout<<endl;
    }
int getSize() const
{return size;
}
};

int main()
{
queue<Process> rq(5);

    rq.enqueue(Process(1, "P1"));
    rq.enqueue(Process(2, "P2"));
    rq.enqueue(Process(3, "P3"));

    rq.display();


    rq.dequeue();
    rq.display();

    rq.enqueue(Process(4, "P4"));
    rq.enqueue(Process(5, "P5"));
    rq.enqueue(Process(6, "P6")); // should say full
    rq.enqueue(Process(7, "P7"));
    rq.display();	
return 0;
}