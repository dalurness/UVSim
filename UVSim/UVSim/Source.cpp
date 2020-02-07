#include <iostream>
#include "newFunction.h"

using namespace std;

int main() {
	cout << "Hello World! Welcome to UVSim!" << endl;
	newFunction();
	anotherNewFunction();
	return 0;
}


/*
SOME SUEDOCODE FOR THE ORGANIZATION/REQUIREMENTS OF THE PROJECT

	class sim
		int Accumulator
		int InstructionCounter
		int InstructionRegister
		int OperationCode
		int Operand
		vector[100] //memory size

	//potentially have the vector grow with the instructions instead of just declaring
	//	it with 100 locations to save memory. This is reliant on the idea that
	//	the user must create their own memory locations for storage like 00000

	//functions
	printMemory()
	getDataFromUser()
	getDataFromFile()
	executeProgram()
	//internal functions
	read()
	write()
	load()
	store()
	add()
	subtract()
	divide()
	multiply()
	branch()
	branchNeg()
	branchZero()
	halt()
	MEMDUMP()
	BREAK()
	CONTINUE()

*/