#include <iostream>

#include "newFunction.h"
#include "simulator.h"

using namespace std;

/***Shaun***/
int main() {
	
	Simulator sim;
	string cmd;
	int memLocation = 0;
	char again;
	
	cout << "| Please enter your program one instruction at a time.   |" << endl;
	cout << "| The memory location of your command will be displayed. |" << endl;
	cout << "| Enter /0 to stop entering your program.                |" << endl;
	cout << "==========================================================" << endl;

	while (0 == 0) {
		if (memLocation < 10) {
			cout << "0" << memLocation << " : ";
		}
		else {
			cout << memLocation << " : ";
		}
		cin >> cmd;
		if (cmd == "/0") {
			break;
		}
		sim.loadCommandIntoMemory(cmd);
		//sim.loadCommandIntoMemory("+1002);
		memLocation++;
	}
	cout << "~ Program Loading Complete ~" << endl << endl;
	cout << "~ Begin Executing Program ~" << endl;
	sim.executeProgram();
	cout << endl << "~ Program Execution Complete ~" << endl << endl;
	sim.printMemory();
		
	cout << "Program Done.";
	
}
/*
	sim.loadCommandIntoMemory("+1002");
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
	*/

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