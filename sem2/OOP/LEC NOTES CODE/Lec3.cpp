//Lec3 by Usama Hassan Alvi
//27 Jan 2025
#include<iostream>
using namespace std;
void display(int* p1, int* p2){
	cout << "memory address: " << p1 << ", value: " << *p1 << endl;
	cout << "memory address: " << p2 << ", value: " << *p2 << endl;
}
void _swap(int* p1, int* p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << *p1 << " " << *p2 << endl; //20, 10
	int a = 70, b = 80;
	p1 = &a;
	p2 = &b;
	cout << *p1 << " " << *p2 << endl; //70, 80
}
void print(int*& p) //p is a reference pointer to integer
{
	cout << *p << endl; //50
	int n1 = 100;
	p = &n1;
//since p is a reference pointer (it is just an alias for p3) so 
//p3 in the main function will also be pointing to n1.
}
void allocateMem(int*& ptr, int &s)
{
	cout << "Enter the size of array: ";
	cin >> s; //5
	ptr = new int[s];
}
int main() {
	int v = 10;
	double height = 5.7;
	char c1 = 'q';
	void* ptr = &v;
	ptr = &height;
	ptr = &c1;
	//The following instruction reads 1 byte from memory and 
	//prints the data 'q' to the console.
	cout << *(char*)ptr << endl;
	//The following instruction reads 1 byte from memory and 
	//prints garbage to the console.
	cout << *(double*)ptr << endl;

	int x = 10, y = 20;
	cout << "before fun call: " << x << " " << y << endl; //10, 20
	//display(x, y); error
//since display function is receiving pointers in the parameters 
//list so we need to send the address of variables x and y in 
//the function call.
	display(&x, &y);
	int* p1 = &x, * p2 = &y;
	cout << "before fun call: " << *p1 << " " << *p2 << endl;
	//passing pointers by value:
	_swap(p1, p2); //function is receiving pointers in the parameters list
	cout << "after fun call: " << *p1 << " " << *p2 << endl;
	//both the pointers p1 and p2 in the main function are still pointing 
	//to x and y.
	cout << &x << " " << p1 << endl;
	cout << &y << " " << p2 << endl;
	//passing pointers by reference:
	int temp = 50;
	int* p3 = &temp;
	print(p3); //p3 will be received in a reference pointer
//p3 is no longer pointing to temp variable
	cout << p3 << " " << &temp << endl;
	cout << *p3 << endl; //what will be the output?

//compare the values using pointers
	p1 = &x;
	p2 = &y;
	//if(p1 < p2) logical error, comparing address
	if (*p1 < *p2) //dereference the pointers to compare the data
		cout << "the data pointed by p2 is lrg\n";
	else
		cout << "the data pointed by p1 is lrg\n";
	//increment the value using pointers
	*p1 = *p1 + 4;
	*p1 += 5; //equivalent to: *p1 = *p1 + 5
	*p2 *= 3; //equivalent to: *p2 = *p2 * 3
	cout << x << " " << y << endl;

	int size;
	cout << "Enter the size of array: ";
	cin >> size; //5
//memory will be allocated on heap and the address of index#0 will
//be stored in the pointer arr. The pointer arr is in the stack.
	int* arr = new int[size];
	//int* data;
//pass pointer by reference to allocate memory
//get the size from user and allocate memory.
	//allocateMem(data, size);  //both parameters are by reference
	for (int i = 0; i < size; i++)
		arr[i] = i + 5; //cin >> ptr[i];
	int* p4 = arr;
	for (int i = 0; i < size; i++)
	{
		cout << "enter data: ";
		cin >> *p4; //dereference the memory to store the user input
		p4++; //move the pointer to next memory location
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " "; 
//you can also print the data by dereferencing the pointer p4
		//p4--;
		//cout << *p4 << " ";
	}
}