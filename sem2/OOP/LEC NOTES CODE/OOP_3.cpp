//inline functions
//constant and non-const member functions
//static data members and static member functions.
//this pointer
#include<iostream>
using namespace std;
class ComplexNumber {
//static data members are shared resources. There exisits only a
//single occurence of a static data member which is shared among 
//all the objects of the class. They are created at class level 
//rather than object level so they are object independent.
//object independent: You can access them without creating an object of class.
//How?
	static int count; //initialize the static data member outside the class
	int real, imaginary; //non-static data members
//non-static data members are object dependent. They are created separately for 
//for each object in ram whenever an object is created.
public:
//Constructor is used to initialize the data members but we are going to
//initialize only non-static data members here. Why not static data members?

//this pointer: A special pointer, pointing to calling object inside the class.
	ComplexNumber(int real = 0, int imaginary = 0) {
		this->real = real;
//this->real (access the "real" data member of calling object)
		this->imaginary = imaginary;
		//real = real; 	//logical error
//Q: why we are using "this" pointer here why not the following method?
		//real = real; //Ans: class data member will remain uninitialized.
//avoid initialization of static data member in constructor. Since it is a shared
//resource so in case of initialization of static data member in constructor, the
//value will be reset for all the objects created so far.
//In this example, static data member "count" will keep the count of active objects.
		count++; //increment the value by 1 to keep the count of active objects in memory
	}
//inline functions: to improve the performance or optimization.
//back end implementation: the code will be generated directly at the point where function is called 
//rather than making traditional function call by pushing the return address
//and local variables on stack.
//Since it will increase the file size so usually smaller functions are kept inline.
	inline void print() {
		cout << real << " " << imaginary << endl;
		cout << count << endl;
	}
//constant member function: usually getter functions and print functions are const
//you can not make any chnage in the class data members inside constant functions.
//However you can make any change in the local variables in constant functions.
	int getReal() const {
		//this->real = r;	     //error
		//this->real++;			//error
		//cin >> this->real;   //error
		//print(); //can not make a function call to a non-constant functions
//since the operators: =, ++, --, >> so it will generate an error if we
//try to make any change in the class data member using these operators.
//k is a local variable so you can use these operators with local variables
		int k = this->real;
		k++;
		cin >> k;
		return this->real + 20;
	}
//static member functions: just like static data members, static member functions
//are also object independent. You can access them without creating an object of class.
//Keep in mind: you can only access static data members inside static functions.
	static void display() {
		cout << count << endl; //display static data member
//The following instruction will generate an error even if you call this function with the
//object of class because "real" is not a static data member.
		//cout << real << endl; //error
	}

//non-static member functions: you can access both the static and non-static data members 
//inside non-static data members.
	void output() const {
		cout << real << " " << imaginary << " " << count << endl;
	}
//destructor: automatically called when object is destroyed.
	~ComplexNumber() {
//decrement the value of count by 1 whenever the object is destroyed to keep
//the actual count of active objects.
		count--;
	}
};
//Initialization of static data member
//dataType className scopeResolutionoperator variableName = value;
int ComplexNumber::count = 10;
int main() {
//calling static member function without object.
//className::methodName();
	ComplexNumber::display(); //0
	ComplexNumber c1(3, 9);
	{
		ComplexNumber c2(7, 9);
		c1.display(); //2
		ComplexNumber c3(4, 12);
		c2.display(); //3
	}
	//c3.display(); //error (created inside the block)
	c1.display(); //1 (c2 and c3 are destroyed)
	c1.output();
//display and output functions are not an inline functions.
//whenever a function is called the local variables and return 
//address of the instruction is pushed on stack and control is 
//transferred to the function, when the function finished execution, 
//the control needs to return.
//it will get the return address from stack and reactive all the 
//local variables. The process of pushing the data on stack and popping
//the data from stack involves an overhead each time a function is called.
	c1.print();
//since print is an inline function so it will not push and pop the data on stcak.
//the source code of print function will be placed at line#244 so it will increase the 
//efficiency in terms of time but the file size will be increased.
}