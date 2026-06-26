//Lec#1 (Usama Hassan Alvi)
//Pointers and reference variable
#include<iostream>
using namespace std;
int main()
{
//Pointer can only store memory address. Memory address is a hexadecimal number.	 
	int* p1;
//p1 is a pointer to integer. It can point to any memory location that contains an integer.	
	int x = 40, y = 60;
	p1 = &x; //p1 is now pointing to variable x
//Task: update the value of variable x using pointer.
	//p1 = 60; invalid assignment. p1 can not store integers.
	*p1 = 20; //The value of x will be updated by dereferencing the pointer.

	const int* p2;
//p2 is a pointer to constant integer. It can point to memory locations containing both constant and non-constant integers.
//However, p2 is given read-only access to the memory location, meaning that you cannot modify the data at that location.
//The pointer itself, though, is free to point to any other memory location.
	const int size = 50;
	p2 = &size;
	p2 = &y; //p2 can only read the data of variable y.
//It is similar to a scenario in computer labs where students are given the right to use the installed software, but they
//cannot install any new software due to restricted access.

	int* const p3 = &x;
//p3 is a constant pointer to an integer.It is similar to a constant integer, where you must initialize the constant at the
//time of declaration, and you cannot modify it afterward.Similarly, once p3 is initialized with a memory location, it will
//always point to that memory location throughout the program.However, you can change the data at that memory location.
	//p3 = &y; Invalid assignment: p3 is a constant pointer, so it cannot point to any other memory location once it is initialized.
	*p3 = 70;

	const int* const p4 = &y;
	//const int* const p4 = &size; //also a valid assignment
//p4 is a constant pointer to constant integer. Since p4 is a constant pointer so it cannot point to any other memory location once 
//it is initialized. Additionally, p4 cannot modify the data at the memory location it is pointing to.
//Remember, the variable y is not a constant integer, yet p4 is still pointing to y.	
	//p4 = &x; invalid assignment. Reason: p4 is a const pointer
	//*p4 = 50; invalid assignment. Reason: p4 can't modify the data.

//Reference variable:
	int& r_var = y; //r_var is a reference variable of y. It will act like an alias of variable y.
	r_var = 80;
	cout << r_var << " " << y << endl; //predict the output

	const int& c_r_var = y; //c_r_var is constant reference variable of y.
	//c_r_var = 100; invalid assignment. The data of c_r_var can't be modified.

//Q: What is the difference between reference variable and pointers?

//Mapping Scenarios to Real - World Problems :
//Case 1 : int pc1, pc2, pc3; int* user;
//In this scenario, there are multiple PCs in a lab, and the user can log in to any of the PCs.
//The user has full access to modify each of the PCs, including installing new software or making other changes.

	//user = &pc1; user = &pc2; user=&pc3; 
	//*user = 80;  

//Case 2: const int* user;
//Here, the user can still log in to any of the PCs in the lab.However, the user is restricted from making 
//any modifications, such as installing software or making changes to the system.

	//user = &pc1; user = &pc2; user = &pc3;
	//*user = 50; error

//Case 3: int* const user;
//In this case, the user is assigned to a fixed, dedicated PC.While the user can make changes
//(such as installing software) on this specific PC, they are no longer able to log in to any 
//other PC in the lab.The user’s access is now limited to this single machine.
//pointer needs to be initialized at the time of declaration.

	//*user = 50;
	//user = &pc3; error

//Case 4: const int* const user;
//Finally, in this scenario, the user is both limited to a specific, dedicated PC and restricted
//from making any changes to it.The user can only view or interact with the system but cannot make
//any modifications, such as installing new software.
//pointer also needs to be initialized at the time of declaration here as well.
	//*user = 50; error
	//user = &pc2; error
}