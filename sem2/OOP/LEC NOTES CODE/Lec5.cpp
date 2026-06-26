//Lec#5 by Usama Hassan Alvi
//1: deletion of dynamically allocated memory
//2: dangling pointer
//3: fetch the data from one array and copying into another
//4: importance of sentinel value at the end of array.

#include<iostream>
using namespace std;
void allocMem(int*& p, int& s)
{
	cout << "Enter the size: ";
	cin >> s; //10
	p = new int[s];
}
void getInput(int* const& p, const int& s)
{
	for (int i = 0; i < s; i++)
	{
		do {
			cout << "Enter +ve element: ";
			cin >> *(p + i);
		} while (*(p + i) < 0);
	}
}
void reSize(int*& p, int& s)
{
	//create a variable to get the new array size and a pointer to point that memory
	int temp_Size = 0, * tempArr = 0;
	//get the new array size from user.
	cout << "Enter the new size: ";
	cin >> temp_Size;
	//memory allocation. "tempArr" pointer is pointing to the array and all the cells are initialized with 0.
	tempArr = new int[temp_Size] {0};

	//The new array size could be either greater than or smaller than the existing array size.
	//so handle both the cases i.e., growth and shinkage.
	if (temp_Size > s)
	{
		//growth: copy all the elements from existing array.
		for (int i = 0; i < s; i++)
			*(tempArr + i) = *(p + i);
	}
	else
	{
		//shrinkage: copy the elements equivalent to the new array size.
		for (int i = 0; i < temp_Size; i++)
			*(tempArr + i) = *(p + i);
	}
	//de-allocate(release) the memory where the pointer "p(alias of ptr)" are pointing 
	delete[] p; //to avoid memory leak
	p = tempArr; //relocate the pointer "p(alias of ptr)" to newly allocated memory 
	s = temp_Size; //update the value s(alias of size)
}
void extEvenVal(const int* const& p, const int& s, int*& e)
{
//steps to follow: 
//1: count the occurence of even values
//2: allocate the memory to "e" (1 extra cell to store a sentinel value -1 why?)
//3: copy the even elements in the "e"
//4: store a sentinel value "-1" at the last index.(indicator for the end of array elements)

	int count = 0;
	//step#1: count occurences of even values
	for (int i = 0; i < s; i++)
	{
		if (*(p + i) % 2 == 0)
		{
			count++;
		}
	}

	//step#2: memory location to e(alias of even).
	e = new int[count+1]; //1 extra cell for sentinel value
	//why sentinel value (indicator for end of array)
	
	//step#3: store even values in "e"
	for (int i = 0, j = 0; i < s; i++)
	{
		if (*(p + i) % 2 == 0)
		{
			*(e+j) = *(p + i);
			j++;
		}
	}
	//step#4: store sentinel value at the last index.
	*(e+count) = -1; 
}
void print(const int *const &ptr)
{
	int i = 0;
	while (*(ptr + i) != -1)
	{
		cout << *(ptr + i) << " ";
		i++;
	}
}
int * extOddVal(const int* const& p, const int& s)
{
	int count = 0;
	//step#1: count the occurences of odd values
	for (int i = 0; i < s; i++)
	{
		if (*(p + i) % 2 != 0)
		{
			count++;
		}
	}

	//step#2: memory allocation to temporary pointer (odd).
	int * odd = new int[count + 1]; //1 extra cell for sentinel value
	//why sentinel value (indicator for end of array)

	//step#3: store odd values in the temporary pointer (odd)
	for (int i = 0, j = 0; i < s; i++)
	{
		if (*(p + i) % 2 != 0)
		{
			*(odd + j) = *(p + i);
			j++;
		}
	}
	//store sentinel value at the last index
	*(odd + count) = -1;
//return the starting address of array where "odd" is pointing.
//return type should be pointer to int i.e., int *
	return odd; 
}
void deAlloc(int*& p, int*& e, int*&d, int*&o)
{
//de-allocate the memory occupied on heap before exiting program.
//
	delete[] p;
	delete[] e;
	delete[] d;
	delete[] o;
	//p,e,d,and o are dangling pointers.
//dangling pointer? a pointer pointing to de allocated memory.
//You need to make sure that there is no dangling pointer in your program.
//Solution: store nullptr,NULL or 0 in the pointers.  
//pointers must be received by reference otherwise the actual pointers
//in the main function remain dangling	pointers.
	p = nullptr; //since p is alias of ptr 
	e = NULL;
	d = 0;
	o = NULL;
}
int main()
{
	int* ptr = 0, size = 0;
//get the array size and allocate the memory on heap. 
//ptr will be pointing to that memory so pass the parameters by reference.
	allocMem(ptr, size); 
	getInput(ptr, size);

//Resize the array. Follow the given steps:
//1: get a new size from user. 
//2: allocate the memory equivalent to the new size to a temp pointer
//3: copy the data from ptr to temp
//4: delete the memory where ptr is pointing to avoid memory leak
//5: relocate ptr to temp.
	reSize(ptr, size);

//fetch the data from one array and copy into another.
	size = 7;
//Initialized the array with hard coded values. 
//you can get the input from user as well.
	int* data = new int [size] {19, 21, 7, 10, 13, 8, 15};
//Task: fetch even elements from data and store in another array.
//create a pointer "even" in the main function and pass this pointer by-reference in the function
	int* even;
	extEvenVal(data, size, even);
//print the even values. sentinel value -1 will be used to terminate the loop.
	print(even); 

//Task: fetch odd elements from the data and store in another array. 
//create a dynamic array in the function, store all the odd elements and return
//the array to main function. Since you are returning the pointer so hold the address
//in a pointer.
	int *odd = extOddVal(ptr, size); 
//The address returned by the function will be stored in "odd" pointer.
	print(odd);

//de-allocate all the dynamically allocated memories.
	deAlloc(ptr, even, data, odd);
	//delete[] odd;

}
//Lec#6 contents (2D dynamic array)
//int r = 3, c = 5;
//int** data;
//data = new int* [r]; //array of pointers
//for (int i = 0; i < r; i++)
//{
//	cout << "Enter the size of array: ";
//	cin >> c;
//	data[i] = new int[c + 1];
//	data[i][c] = -1;
//}
//int* ptrArr[4];
