//Lec#6 by Usama Hassan Alvi
//2D dynamic arrays.

#include<iostream>
using namespace std;
int* getFactors(const int& v)
{
//steps to follow:
//1: count the number of factors
//2: allocate the memory to a "temp" pointer
//3: store the factors and sentinel value
//4: return the array(temp pointer) to main function.

//step#1: count the factors
	int count = 0;
	for (int i = 1; i <= v; i++)
	{
		if (v % i == 0)
			count++;
	}
//step#2: memory allocation
	int* temp = new int[count + 1];
//step#3: store factors and sentinel value
	for (int i = 1, j=0; i <= v; i++)
	{
		if (v % i == 0)
		{
			*(temp + j) = i;
			j++;
		}
	}
	*(temp + count) = -1;
//step#4: return the temp pointer
	return temp;
}
int main()
{
	int r = 4, c = 5;
	int** data;
//since data is a double pointer so it can point to a pointer.
	//data = new int[10]; error
	data = new int* [r]; //data will be pointing to an array pointers.
//index#0 of the array pointers (pointed by data) is pointing to an array of integers of size 10.
//both of the following syntax are valid.
	data[0] = new int[10]; //*(data + 0) = new int[10];
//index#1 of array pointers is pointing to an array of integers of size 20
	data[1] = new int[20]; //*(data + 1) = new int[20];
//We want to allocate a memory at each index of array of pointers
	for (int i = 0; i < r; i++)
	{
//fixed size arrays in each row of 2D array
		*(data + i) = new int[50];
//Each index of the array of pointers will be pointing to an 
//array of integers of size 50.
	}

//allocate memory of different size to each row of 2D array.
	for (int i = 0; i < r; i++)
	{
//dynamic size arrays in each row of 2D array.
//get the array size from user.
		cout << "Enter the size: ";
		cin >> c;
//allocate one extra cell for a sentinel value -1.
		*(data + i) = new int[c + 1];
		data[i][c] = -1; 
//Store a sentinel value at the last index so that we can easily 
//process the arrays later on. Otherwise, there would be no way to 
//terminate the loops while processing arrays of different lengths.
	}
	
//get the input from user.
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; data[i][j] != -1; j++)
		{
			cout << "Enter a positive element: ";
			cin >> data[i][j];
		}
	}
//Task: Store the factors of each element of the array.
	const int size = 5;
	int elem[size] = {20, 15, 17, 40, 19 };
//you need a 2D array here to store the factors. (one row for 
//storing the factors of each element)
//how many rows are there in 2D array?
	int** factors = new int* [size];
//factors is pointing to an array of pointers.
	for (int i = 0; i < size; i++)
	{
//getFactors function will return a 1D array.
		factors[i] = getFactors(elem[i]);
//try to implement getFactors function with void return type.
//you can change the parameters list.
	}

//display the factors of each element
	for (int i = 0; i < size; i++)
	{
		cout << "factors of " << elem[i] << ":";
		for (int j = 0; factors[i][j] != -1; j++)
		{
			cout << factors[i][j] << " ";
		}
		cout << endl;
	}
}