//1: Member Initializer list to initialize the data members in constructor.
//2: this pointer to access the data members of calling object.
//3: cascading (return the object and pointer from function)
//4: create an object on heap and use of -> operator to access member function.
//5: static Array of objects. use {} to send the parameters in the ctr 
// for the data members of each index.
//6: use of && to make the reference variable of constants.

#include<iostream>
using namespace std;
class Student {
	int s_id;
	float cgpa;
public:
//Constructor using Member initializer list method to initialize the data members.
	Student():s_id(0), cgpa(0) //keep in mind that s_id(0) and s_id = 0 both are same
	{} //it is mandatory to write curly brackets otherwise syntax error
	Student(int id, int c) : s_id(id), cgpa(c)
	{
//this pointer: A special pointer that points to the calling object of class
//to access the data members of object using "this" pointer, you can either 
//use arrow operator (->) or use the dot operator (.) by dereference this pointer.
		cout << "this pointer with -> operator: " << this->s_id << " " << this->cgpa << endl;
//cout << *this.cgpa; //error (precedence of dot operator is greater than * operator)
		cout << "dereference this pointer: " << (*this).s_id << " " << (*this).cgpa << endl;
//Apply parenthesis to increase the precedence of * operator.
	}
	void display() {
		cout << "display function is called\n";
	}
	Student print() {
		cout << "print function is called\n";
		return *this; //dereference this pointer to return an object.
//incase if you return "this" then return type will be Student* because 
//"this" is a pointer to calling object.
	}
	void output() {
		cout << s_id << " " << cgpa << endl;
	}
};
int main()
{
	Student s1; //default ctr will be called.
	Student s2(701, 3.7); //parameterized ctr is called.
	
	//s1.display().print(); 
//error(There is a calling object for display function but for print
//function there is no calling object because return type of display is 
//void. There must be calling object for print function.)

	s1.print().display(); 
//it is a valid function call. s1 is the calling object for print and print 
//function returns the same calling object by dereferencing this pointer.

	Student* obj = new Student(702, 3.5);
//create an object on heap and store the address in a pointer "obj"
	obj->output(); //use arrow operator -> to access the member functions using pointer
	
	delete obj; //delete the object to release the memory
	obj = nullptr; //to avoid dangling pointer.
	
	Student s_Arr[3] = { {801,3.3}, {802,3.5}, {803, 3.7}};
//create a static array of objects. use curly brackets to send the parameters.
	s_Arr[0].output();
	
	//int& ref = 6; //error
	int&& ref = 10; //ref will be a reference variable to the memory allocated to 10
	cout << ref << " " << &ref << endl;
}