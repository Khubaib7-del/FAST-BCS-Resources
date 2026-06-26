//Lec#4 by Usama Hassan Alvi

#include<iostream>
using namespace std;
//receiving pointer and int variable by reference. Any change
//in these parameters will also be reflected in main function
//because "p" and "s" are alias of an existing memories.
//It is mandatory to pass the parameters by reference in this function.
void allocMem(int *&p, int &s) // p is a reference pointer to integer
{
//This function will be used to get the array size from user
//and memory allocation of array.
	cout << "Enter the size: ";
	cin >> s;
	p = new int[s]; 
//memory will be allocated on heap and a pointer p will be pointing 
//to the 0th index.
}

//receiving by reference const parameters.
//p is a reference const pointer to integer.
//why reference const pointer? why not only a pointer or a just reference 
//pointer? Reason inside the body of function
void getInput(int * const&p, const int& s)
{
//it is optional to pass the parameters by reference in this function.
//Reason behind passing parameters by reference is to use the memory 
//resources effeciently. Whenever a parameter is received by reference,
//an alias is created for an existing memory block instead of creating a 
//new memory block.
//Why keeping them const as well why not just a reference pointer?
//if "p" is by reference then any change in "p" will relocate it to any
//other memory location and you will lost the data. 
//like p = &s; "p" will point to "s" and we will no longer be able to 
//access the memory allocated for array (where "p" was previously pointing)
 	for (int i = 0; i < s; i++) {
		cout << "Enter the data: ";
		cin >> *(p + i); //do not use [] operator
		//both p[i] and *(p+i) will behave exactly the same
//*(p+i); jump "i" blocks from "p" and dereference the memory to store the data
	}
	//p = &s; error(since p is const)
	//p++; error(p is const)
	
	//*(p+4) = 500; 
//valid assignment, p can't change its position however it can change the 
//data of memory locations where it is pointing.
}

//p is a reference const pointer to const integer.
//why const integer? The purpose of print function is just to print 
//the data on console rather changing the data in memory. if we keep
//it just reference pointer to integer then "p" can point to any other
//memory location, if we keep it const reference pointer then "p" will 
//be unable to change its position but still it can change the data of 
//memory locations where it is pointing, If we want to prevent a pointer 
//from changing its position and also make the memory location it points 
//to immutable(unchangeable), we can use a const pointer to a const integer.
void print(const int* const& p, const int& s)
{
	for (int i = 0; i < s; i++)
		cout << *(p + i) << " ";
	//p = &s; error (p is const)
	//*(p+4) = 600; error
//(p can not make any change in the memory locations it is pointing to due
//to const int in the definition i.e., pointing to const integer)
}

void grow(int*& p, int& s)
{
//we want to increase the size of array by 3 times. 
//create a temp array
	int* temp = new int[s * 3];
//copy the data from existing array
	for (int i = 0; i < s; i++)
		*(temp + i) = *(p + i);
//now store the address of newly allocated array in "p"
	p = temp;
//update the size variable s
	s *= 3;
}
int main()
{
	int size, * ptr = &size;
	allocMem(ptr, size);
	getInput(ptr, size);
	print(ptr, size);
	grow(ptr, size);
}