#include <iostream>
#include <fstream>
#include "chain.h"
using namespace std;

int main (int argc, char *argv[]){

	if(argc < 2)
	{
		cout << "Enter the file name as input" <<endl;
		return 0;
	}
	
	
	//Creates new chain
	chain *mychain = new chain(100);
	
	mychain->insert(0, 85);
	mychain->insert(1, 87);
	mychain->insert(2, 27);
	mychain->insert(3, 20);
	mychain->insert(4, 56);
	mychain->insert(5, 64);
	mychain->insert(6, 43);
	mychain->insert(7, 21);
	mychain->insert(8, 95);
	mychain->insert(9, 8);
	mychain->insert(10, 11);
	mychain->insert(11, 14);
	mychain->insert(12, 17);
	mychain->insert(13, 62);
	mychain->insert(14, 57);
	mychain->insert(15, 5);
	mychain->insert(16, 93);
	mychain->insert(17, 73);
	mychain->insert(18, 74);
	mychain->insert(19, 6);
	mychain->insert(20, 86);
	mychain->insert(21, 91);
	mychain->insert(22, 99);
	mychain->insert(23, 88);
	mychain->insert(24, 79);
	mychain->insert(25, 85);

	
	int multOf = 5;
	
	// Read the file with filename stored in argv[1]. Store the numbers in mychain. 
	
	mychain->readAndStoreFromFile(argv[1]);

	

	//Print mychain
	cout<<"\n\n The list is : "<<endl;
	mychain->output();
	system("pause");
	// Delete all entries from mychain which contain element that is multiple of variable multOf
	
	mychain->eraseModuloValue(multOf);
	
	//Print mychain
	cout<<"\n\n The list after removal of elements with multiple of 5 is : "<<endl;
	mychain->output();
	
	//Reorder mychain such that all odd numbers precede all even numbers.
	//Note that the original ordering between odd (even) numbers should remain intact. 
	//Example: 3 4 5 1 2 will become 3 5 1 4 2. But, 5 1 3 4 2 is not valid.
	mychain->oddAndEvenOrdering();
	
	
	//Print mychain
	cout<<"\n\n The list after odd and even ordering is : "<<endl;
	mychain->output();
	
	
	//Reverse the mychain
	mychain->reverse();
	
	//Print mychain
	cout<<"\n\n The reversed list is : "<<endl;
	mychain->output();
	system("pause");
	

}
