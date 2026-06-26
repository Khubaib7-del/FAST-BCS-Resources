#include<iostream>
#include<memory>
#include<string>
using namespace std;
//OOP: Whenever we want to work with real-world entities, we need object-oriented programming.
//OOP provides: 1(Abstraction), 2(Encapsulation), 3(Inheritence), 4(Polymorphism)
//What is class? A user defined data type or abstract data type(ADT)
//Why we need class? to create our own data types (to achieve abstraction)
//A class have private data members and public methods.
//methods include constructors and member functions
class student
{
//keep the attributes or data members of class always private
//they are by default private so you do not need to write anything.
	int student_id;
	string name;
	float cgpa;
public: //access specifier
//keep all the methods of class as public.
//constructor: method of a class to initialize the data members	
//constructor will be called automatically wheneven an object of class is created
	student() //default constructor (it will not receive any parameter)
	{
		cout << "default ctr is called\n";
		student_id = 0; 
		name = " ";
		cgpa = 0.0;
	}
	student(int id, string n, float c) //parameterized constructor
	{
		cout << "parameterized ctr is called " << id << endl;
		student_id = id; //it will store the id in the "student_id" of calling object
		name = n; //it will store the n in the "name" of calling object
		cgpa = c; //it will store the c in the "cgpa" of calling object
	}
//member functions of class (always public)
	//setter function
	void setData(int id, string n, float c)
	{
		cout << "set data is called\n";
		student_id = id; //it will store the id in the "student_id" of calling object
		name = n; //it will store the n in the "name" of calling object
		cgpa = c; //it will store the c in the "cgpa" of calling object
	}
	void print(){
		cout << "print is called\n";
		//it will print the data members of calling object
		cout << "id: " << student_id << " name: " << name << " cgpa: " << cgpa << endl;
	}
	void setCGPA(float c)
	{
		cgpa = c; //data member of calling object will be assigned the value of c
	}
	float getCGPA()
	{
		return cgpa; //it will return the cgpa of calling object.
	}
//Destructor: it will be called automatically whenever the object is destroyed.
//objects are created on stack. Create three to four objects in main and check the sequence of
//constructors and destructor calling.
	~student()
	{
		cout << "dtr is called " << student_id << endl;
	}
};
int main(){
//compiler provides: default constructor, destructor, assignment operator, and copy constructor
//constructor will be called automatically whenever an object is created
//once a constructor is created in class, the default constructor of compiler is no longer available.

	student s1(701, "Usama", 3.47); //s1 is an object of student class
	s1.setCGPA(3.57); //s1 is the calling object
	cout << s1.getCGPA() << endl; //it will print the cgpa of calling object on console
	s1.print();
	
	student s3(703, " ", 3.97);
	s1.setData(701, "Usama", 3.47); //s1 is the calling object
	s1.print(); //s1 is the calling object


	//Reset function of smart pointers:
	//create a unique pointer that will point to an array of integers.
	unique_ptr<int[]> u1(new int[5]{10,20,30,40,50 });
	for (int i = 0; i < 5; i++)
	{
		cout << u1[i] << " ";
	}
	cout << endl;

//reset function will deallocate the memory where u1 was pointing,
//so there will be no memory leak. Now it will allocate a memory 
//equivalent to the number of memory blocks mentioned in [] 
//and stores the address of this new memory location in u1.
//now u1 is pointing to an array of 3 integers which is initialized with 3,7,9.
	u1.reset(new int[3]{ 3,7,9 });
	for (int i = 0; i < 3; i++)
	{
		cout << u1[i] << " "; //it will print the values 3,7, and 9.
	}
	cout << endl;
}