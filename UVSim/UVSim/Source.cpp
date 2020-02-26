#include <iostream>
#include "simulator.h"

using namespace std;

int main() {
	
	Simulator sim;
	sim.loadCommandIntoMemory("+1002");
	sim.loadCommandIntoMemory("+1100");
	sim.loadCommandIntoMemory("+1102");
	sim.loadCommandIntoMemory("+4300");
	sim.loadCommandIntoMemory("+0000");
	sim.loadCommandIntoMemory("+0000");
	sim.loadCommandIntoMemory("+0192");
	sim.loadCommandIntoMemory("+1262");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("+3453");
	sim.loadCommandIntoMemory("+0594");
	sim.loadCommandIntoMemory("+8394");
	sim.loadCommandIntoMemory("+0293");
	sim.loadCommandIntoMemory("+1827");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("+1111");
	sim.loadCommandIntoMemory("-9999");
	sim.loadCommandIntoMemory("+1234");
	sim.loadCommandIntoMemory("+0495");
	sim.loadCommandIntoMemory("+9483");
	sim.loadCommandIntoMemory("+0495");
	sim.loadCommandIntoMemory("+9384");
	sim.loadCommandIntoMemory("+1262");
	sim.loadCommandIntoMemory("+3849");
	sim.loadCommandIntoMemory("+3849");
	sim.loadCommandIntoMemory("+3849");
	sim.loadCommandIntoMemory("+3849");
	sim.loadCommandIntoMemory("+3849");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("-3849");
	sim.loadCommandIntoMemory("+9999");
	sim.executeProgram();
	sim.printMemory();
	
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



*/