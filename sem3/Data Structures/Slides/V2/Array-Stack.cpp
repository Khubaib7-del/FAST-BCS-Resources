# include<iostream>
using namespace std;
template <typename T>
class stack{
T *A;
int size;
int capacity;
int current;
public:
stack(int cap=0)
{if(cap>0)
{//stack<int> s(100);
A=new T[cap+1];
capacity=cap+1;
}
else
{//stack<int> s;
A=NULL;
capacity=0;
}
current=-1;
size=0;
}
void push(const T& data)
{
	if((size+1)==capacity)
	{
	T *temp=new T[capacity*2];
	int i=0;
	while(i<size)
	{temp[i]=A[i];
	i++;
	}
	delete[] A;
	A=temp;
	capacity*=2;
	A[++current]=data;		
	}else if(capacity==0)
	{A=new T[1];
	capacity=1;
	A[++current]=data;
	}
	else
	{
	A[++current]=data;
	}
	
	size++;
		}
T pop()
{if((size+1)==capacity/2)
{
T *temp=new T[capacity/2];
	int i=0;
	while(i<size)
	{temp[i]=A[i];
	i++;
	}
	delete[] A;
	A=temp;
	capacity/=2;
	size--;
	return A[current--];	
}else
{size--;
return A[current--];
}
		}		
const T& top()
{return A[current];
	}	
bool isEmpty()
{if(size==0)
return true;
else 
return false;
}
};

int main()
{
stack<char> s;
for(char i='A';i<='Z';i++)
{s.push(i);
}
for(int i=0;i<27;i++)
{if(!s.isEmpty())
{cout<<"Element popped: "<<s.pop()<<endl;
}else
{cout<<"stack is empty"<<endl;
}
}
return 0;
}