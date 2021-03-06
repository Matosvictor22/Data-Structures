#include <iostream>
#include<stdlib.h>
#include<fstream>
#include "mainProgramInterface.h"
#include "derivedChainStack.h"
#include "derivedChainQueue.h"

using namespace std;

bool mainProgramInterface::checkPalindrome(long theNumber)
{
	//Write your code here. This method returns true if theNumber is a Palindrome number
	//else returns false.
	derivedChainStack stack;
	int size = 0;
	while (theNumber > 9){
		stack.push(theNumber % 10);
		size++;

		//  cout<<*stack.top() << endl;
		theNumber /= 10;
	}

	size++;
	stack.push(theNumber);
	// cout<<*stack.top() << endl;

	int array[size];

	for (int i = 0; i< size; i++){
		array[i] = *stack.top();
		cout << *stack.top();
		stack.pop();
	}

	for (int i = 0; i< size; i++){
		stack.push(array[i]);
	}

	for (int i = 0; i<size; i++){
		if (array[i] != *stack.top())
			return false;
		else
			stack.pop();
	}
	return true;



}

bool mainProgramInterface::validSequence(int *theSequence, int n)
{
	//Write your code here. This method returns true if the Input Sequence is valid
	//else returns false.
	derivedChainStack stack;
	for (int i = 0; i < n; i++){
		stack.push(*(theSequence + i));
		int oweFive = 0;

		while (!stack.empty()){
			if (*stack.top() == 10)
				oweFive++;
			else{
				if (oweFive >0)
					oweFive--;
			}
			stack.pop();
		}
		if (oweFive != 0)
			return false;
		else
			return true;
	}
}

void mainProgramInterface::duplicateStack(derivedChainStack* source, derivedChainStack* dest)
{
	//Write your code here. This method copies content of source stack to
	//the destination stack. The content should be exactly same.
	int size = 0;
	while (!source->empty()){
		dest->push(*source->top());
		source->pop();
		size++;
	}
	int array[size];
	for (int i = 0; i<size; i++){
		array[size] = *dest->top();
		dest->pop();
	}

	for (int i = 0; i<size; i++){
		dest->push(array[i]);
		source->push(array[i]);
	}

	delete[] array;
}

int mainProgramInterface::lastCutomer(int m, int n)
{
	//Write your code here. Returns the index of the last customer within m customers.
	derivedChainQueue queue;
	int poppedValue;
	for (int i = 1; i <= m; i++){
		queue.push(i);
	}

	for (int i = 0; i < m - 1; i++){
		for (int j = 0; j < n; j++){
			poppedValue = *queue.front();
			queue.pop();
			queue.push(poppedValue);
		}

	}
	return *queue.front();
}

void mainProgramInterface::call_Palindrome()
{

	cout << endl << endl << "Check for Palindrome " << endl << endl;
	ifstream myfile;
	long num;
	myfile.open(file1);
	for (int i = 0; i<4; i++)
	{
		myfile >> num;
		if (checkPalindrome(num))
			cout << "The number " << num << " is a Palindrome number" << endl;
		else
			cout << "The number " << num << " is not a Palindrome number" << endl;


	}

	myfile.close();

}
void mainProgramInterface::call_validSequence()
{

	cout << endl << endl << "Check for Valid Sequence " << endl << endl;
	ifstream myfile;
	int *sequence;
	int length;
	myfile.open(file2);
	for (int i = 0; i<4; i++)
	{
		myfile >> length;
		sequence = new int[length];
		for (int i = 0; i<length; i++)
			myfile >> sequence[i];
		cout << endl << "The Sequence is : " << endl;
		for (int i = 0; i < length; i++)
			cout << sequence[i] << " ";
		cout << endl;

		if (validSequence(sequence, length))
			cout << "The Sequence is a valid sequence" << endl;
		else
			cout << "The Sequence is not a valid sequence" << endl;

		delete sequence;

	}

	myfile.close();




}

void mainProgramInterface::call_dupStack()
{

	cout << endl << endl << "Output for Stack Duplicate " << endl << endl;
	ifstream myfile;
	int length;
	int temp;
	myfile.open(file3);
	derivedChainStack *myStack, *myStack1;
	for (int i = 0; i<3; i++)
	{
		myfile >> length;
		myStack = new derivedChainStack(length);
		myStack1 = new derivedChainStack(length);
		for (int i = 0; i<length; i++)
		{
			myfile >> temp;
			myStack->push(temp);
		}


		duplicateStack(myStack, myStack1);
		cout << "The source stack is : ";

		myStack->printStack();

		cout << "The copied stack is : ";

		myStack1->printStack();


		myStack->~derivedChainStack();
		myStack1->~derivedChainStack();

	}

	myfile.close();

}
void mainProgramInterface::call_lastCustomer()
{

	cout << endl << endl << "Output for Last Customer program " << endl << endl;
	cout << "The last customer with lastCutomer(12, 5) is " << lastCutomer(12, 5) << endl;
	cout << "The last customer with lastCutomer(10, 6) is " << lastCutomer(10, 6) << endl;
	cout << "The last customer with lastCutomer(10, 3) is " << lastCutomer(10, 3) << endl;
	cout << endl << endl;

}
