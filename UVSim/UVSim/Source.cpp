#include <iostream>
#include "simulator.h"

using namespace std;

/***Shaun***/
int main() {
	
	Simulator sim;
	string cmd;
	int memLocation = 0;
	char again;
	while (0 == 0) {
		cout << "| Please enter your program one instruction at a time.   |" << endl;
		cout << "| The memory location of your command will be displayed. |" << endl;
		cout << "| Enter /0 to stop entering your program.                |" << endl;
		cout << "==========================================================" << endl;

		while (0 == 0) {
			if (memLocation < 10) {
				std::cout << "0" << memLocation << " : ";
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

		cout << "Would you like to enter another program? (Y or N): ";
		cin >> again;
		if (again == 'Y' || again == 'y') {
			cout << endl;
			continue;
		}
		else {
			cout << "Program Done.";
			break;
		}
	}
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