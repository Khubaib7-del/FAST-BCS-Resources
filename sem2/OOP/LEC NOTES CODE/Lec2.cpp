//Lec#2 (Usama Hassan Alvi)
#include<iostream>
using namespace std;
int main()
{
//void pointers: can hold the address of variables of all the data types.
	int x = 40;
	double height = 5.7;
	char c1 = 'q';
	void* ptr = &x; //address of x will be stored in ptr
	ptr = &height; //address of height will be stored in ptr
	ptr = &c1; //address of c1 will be stored in ptr
//Let's try dereferencing the pointer:
	//cout << *ptr << endl; predict the output
//it will generate an error
//Reason: The pointer does not know how much memory it will read for the data.
//if you have pointer to integer like int *p1, In this scenario, p1 exactly knows
//the size of the memory from which data is read i.e.,(4 bytes). Dereferencing of 
//void pointers is slightly different. you need to explicitly mention what type of 
//data void pointer is pointing to. like in this scenario the current status of 
//void pointer is it is pointing to char. 
	cout << *(char*)ptr; 
// (char*) will provide the information to the compiler that ptr is pointing to char
// and an additional * before parenthesis is to dereference the memory location where 
// void pointer is pointing. It will read the data from the memory of 1byte.
	cout << *(double *)ptr << endl; //is it a valid statement?
//ptr is pointing to char but we are writing *(double *). 
//Yes it is a valid statement however ptr will read the data from the memory of 8bytes
//and garbage value will be printed.

//Pointer to pointer (double pointers)
	//int x = 4, y = 20, z = 8;
	//int* ptr = &x; //ptr is a pointer to integer

	//int**p1 = &ptr;
//what is p1?
	//p1 is a pointer to ptr
	//put the definition of "ptr" here
	//p1 is a pointer to (pointer to integer)
//declaration: int**p1 //p1 is a pointer to (pointer to integer)
	// p1 = &y; //is it a valid assignment?
//No it is not. We are trying to assign the address of an 
//integer to (pointer to pointer to integer).
	// *p1 = y; //is it a valid assignment
//No it is not. Since p1 is not a pointer to integer so if we dereference
//p1 it means we are in the block of pointer where p1 is pointing which is 
//ptr in this case and the ptr itself is a pointer, can not store an integer.

	//*p1 = &y; //is it a valid assignment?
//Yes it is. by dereferencing p1 we are in the block of pointer where
//p1 is pointing and it will store the address of int variable y in the
//block of ptr. Now ptr is pointing to variable y.    
	
	//**p1 = x+5; double dereferencing. is it possible here and what will be the outcome?
//Yes it possible in this scenario. You can dereference only pointers. Since p1 is a pointer
//to pointer to integer so the 1st * will take you the block of ptr i.e.,(where p1 is pointing)
//and the 2nd * will take you the block of integer variable y i.e.,(where ptr is pointing) and
//it will store the sum of x and 5 in the memory block of variable y.
	//cout << y << " " << *ptr << " " << **p1 << endl; //predict the output

	//int **p3 = &p1; is it a valid assignment?
//No it is not. Why? p1 is already a pointer to pointer to intger (double pointer), you can not 
//store its address in another double pointer. To make it a valid assignment p3 must be a triple pointer.

	//int **p3 = p1; //is it a valid assignment?
//Yes it is.
//What is p3? p3 is a pointer to pointer to integer. It means p3 will hold the address of a pointer and that
//pointer will point to an integer.
//why this assignment is valid? 
//p1 is holding the address of pointer and that pointer is pointing to an integer so we can store the data of
//p1 in the memory block of p3. Now p1 and p3 both are pointing to ptr.

	//*p3 = &z;
	// x = 50;
	//cout << **p1 << " "<< *ptr << endl; //predict the output
//Since p3 and p1 both are pointing to ptr. By dereferencing p3 we are assigning the address of z in the memory 
//block of ptr so now ptr is pointing to variable z.

//Postfix increment using pointer.

	//int * temp = &x; //temp is pointing to x and value of x is 50
	//*temp++;
	//cout << x << " " << *temp << endl; //predict the output
//Precedence of ++ operator is higher than * operator so it will move the pointer to next memory location first 
//and then dereference that memory location. So value of x will remain unchanged however ptr is no longer pointing to x.
//To increment the value of x using postfix operator with pointer we need to apply parenthesis around *ptr  
//	temp = &x; //temp is again pointing to x.
// do you think we can also use temp-- to relocate the temp to integer variable x? 

	//(*temp)++; //dereference the pointer first and then increment the value of the memory block where temp was pointing by 1.
	//cout << x << endl;
}