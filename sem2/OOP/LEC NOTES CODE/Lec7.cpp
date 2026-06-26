//Lec#7 by Usama Hassan Alvi
//1: Declare a dynamic 2D array having -1 in the data.
//2: store the number of columns at the 0th index to keep track of columns in each row.
//3: implement a function getFactors with void return type
//4: smart pointers 
//The motivation behind smart pointers is to prevent memory leaks and avoid 
//dangling pointers by automatically managing memory allocation and deallocation.
//use header file "memory" while using smart pointers.
#include<iostream>
#include<memory>
using namespace std;

void allocMemory(int**& data, int& r)
{
	cout << "Enter the number of rows: ";
	cin >> r;
	data = new int* [r];
	int cols; //local variable to get the input from user
	for (int i = 0; i < r; i++)
	{
		cout << "Enter the number of cols: ";
		cin >> cols;
//allocate the memory one greater than the number of cols (extra cell to store the array size).
		*(data+i) = new int[cols + 1];
//store the column size at 0th index. i.e., data[i][0] = cols;
		*(*(data + i) + 0) = cols;
	}
}
//data is a by reference constant pointer to constant pointer to constant integer. 
void getInput(int* const* const& data, int& r)
{
	for (int i = 0; i < r; i++)
	{
		cout << "\tinput for row#: " << i << ":" <<endl;
		//since the index#0 contains the number of cols so start the inner loop from index#1.
		for (int j = 1; j <= *(*(data + i) + 0); j++)
		{
			cout << "Enter the data: ";
			cin >> *(*(data + i) + j);
		}
	}
}
//data is a by reference constant pointer to constant pointer to constant integer.
//neither data can point to any other location nor any index of (array of pointers) 
//can point to any other memory location. Additionaly the integer which is pointed by 
//these pointers is also constant.
void print(const int* const* const data, int& r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 1; j <= *(*(data + i) + 0); j++)
			cout << *(*(data + i) + j) << " ";
		cout << endl;
	}
}
//clear the memory resources allocated on heap.
void clearMemory(int**& data, int& r)
{
	for (int i = 0; i < r; i++)
	{
		delete[] *(data+i); //delete the memory allocated to each row of array pointers
	}
	delete[] data; //delete the array of pointers where data is pointing.
	data = nullptr; //to avoid dangling pointer.
}

//since return type is void so receive a by reference pointer in parameters list.
void getFactors(const int& v, int*& ptr)
{
// complete the function (already done in the last lecture)
// The only difference is that we will use the pointer "ptr" for memory allocation 
// and to store the factors.
}
int main()
{
	int** data;
	int r;
	allocMemory(data, r); //pass the parameters by reference
	getInput(data, r);
	print(data, r);
	clearMemory(data, r);

	int arr[5] = { 50, 70, 19, 28, 31 };
	int** factors = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		getFactors(arr[0], factors[i]);
	}

//smart pointers:
//The motivation behind smart pointers is to prevent memory leaks and avoid 
//dangling pointers by automatically managing memory allocation and deallocation.
//There are three main types of smart pointers (unique_ptr, shared_ptr, and weak_ptr) 

	unique_ptr<int> u1(new int); //u1 is a pointer, pointing to an integer on heap.
	*u1 = 20; //store an integer value by dereferencing the pointer 
	cout << *u1 << endl;

	int size = 7;
	unique_ptr<int[]> u2(new int[size]); //u2 is a pointer, pointing to an array of integers.
	for (int i = 0; i < size; i++)
	{
		u2[i] = 20 + i;
	}
	for (int i = 0; i < size; i++)
	{
		cout << u2[i] << " ";
//if you want to dereference the unique_ptr then use get() function as given below.
		//cout << *(u2.get() + i) << " ";
	}

//In unique_ptr, there is a concept of ownership. The memory pointed by the pointer
//u2 can not be pointed by any other pointer at the same time.
	
//create a "temp" unique_ptr
	//unique_ptr<int[]> temp; 
//assign the address of memory that u2 is pointing to the "temp" pointer.
	//temp = u2;  error (the memory pointed by u2 can not be pointed by any other pointer at the same time)

//solution: transfer the ownership. Remember that after transfering the ownership u2 will no longer 
//point to the memory it was pointing to previously.
	unique_ptr<int[]> temp;
	temp = move(u2); //you can use built-in move function to transfer the ownership

	for (int i = 0; i < size; i++)
		cout << temp[0] << " ";
	//cout << u2[0]; //since the ownership is transfered so it will print nothing.

	//unique_ptr<int> u(new int [size]);
	//u[0] = 25; error(u is not pointing to an array of integers. definition is incomplete)
	//to make it point to an array of integers, use [] sign in <> e.g., unique_ptr<int[]>

//shared_ptr: 
//In shared_ptr, the memory pointed by one shared pointer can be pointed by any other shared pointer as well.

	shared_ptr<int[]> s1(new int[size]); //s1 is a pointer to an array of integers.
	for (int i = 0; i < size; i++)
	{
		s1[i] = 50 + i; 
	}
//create another shared pointer and make it point to s1.
	shared_ptr<int[]> s2; //s2 is a pointer to an array of integers.
	s2 = s1; //s2 will also be pointing to the memory pointed by s1.
//you can create as many shared pointers as you can and make them point to s1.
	shared_ptr<int[]> s3; //s3 is a pointer to an array of integers.
	s3 = s2;
//To check how many pointers are pointing to the memory, you can use the function use_count()
	cout << endl << s1.use_count() << " " << s2.use_count() << " " << s3.use_count() << endl;
//use_count() will return the reference count of pointers pointing to the same memory.
//All the output values will be exactly the same i.e., 3 (since three pointers are pointing to the same memory)
	
//so far we have discussed unique_ptr and shared_ptr. you can allocate the memory using both types of
//pointers and also store the data in the corresponding memory blocks as well by using the relevent pointers.

//weak_ptr: We use weak_ptr to avoid cyclic reference(will discuss cyclic reference later on)
//weak pointer can not allocate the memory by its own. it will act as an observer and can point
//to a shared pointer without increasing the reference count.

	//weak_ptr<int[]> w1(new int[size]); //error (can not allocate the memory)
	weak_ptr<int[]> w1;
	w1 = s2;
//w1 is also pointing to the memory pointed by s1, s2, and s3.
	//w1[0] = 75; //error (w1 is an observer, can't make any change in data)
	//cout << w1[0] << endl; //error(w1 can't even read the data from the memory it is pointing to)

	cout << w1.use_count() << endl; 
//output will be 3(but in addition to s1, s2, and s3, w1 is also pointing to the same memory)
//so weak pointer will not increase the reference count
//reference count: count of pointers pointing to the same memory.

//you can see that a weak pointer can't even access the memory to read the data.
//we can use lock() function to read and write the data using weak pointers.
	for (int i = 0; i < size; i++)
		cout << w1.lock()[i] << " ";
	w1.lock()[0] = 15;
	cout << endl << w1.lock()[0] << endl;
}