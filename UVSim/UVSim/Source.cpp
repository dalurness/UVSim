#include <iostream>
#include "simulator.h"

using namespace std;

/***Shaun***/
int main() {
	//variables and instance of sim.
	Simulator sim;
	string cmd;
	int memLocation = 0;
	char again = 'N';
	int end = 0;

	//Get program from user.
	while (end == 0) {
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

			//Exception handling for loading commands into memory.
			try {
				sim.loadCommandIntoMemory(cmd);
			}
			catch (const exception e1) {
				if (e1.what() == "Memory overflow") {
					cout << "An exception occurred: " << e1.what() << endl << "Please re-enter program: " << endl << endl;
					sim.clearProgram();
					memLocation = 0;
					continue;
				}
				else {
					cout << "An exception occurred: " << e1.what() << endl << "Please re-enter instruction: " << endl;
					sim.clearLast();
					//sim.clearProgram();
					//--memLocation;
					continue;
				}
			}


			//sim.loadCommandIntoMemory("+1002);
			memLocation++;
		}

		cout << "~ Program Loading Complete ~" << endl << endl;
		cout << "~ Begin Executing Program ~" << endl;

		//Exception handling when executing program.
		try {
			sim.executeProgram();
		}
		catch (const exception e2) {
			if (e2.what() == "No Halt Statement") {
				cout << "An exception occurred: " << e2.what() << endl << "Please re-enter program: " << endl << endl;
				sim.clearProgram();
				memLocation = 0;
				continue;
			}
			else {
				cout << "An exception occurred: " << e2.what() << endl << "Please re-enter program: " << endl << endl;
				sim.clearProgram();
				memLocation = 0;
				continue;
			}
			
		}

		cout << endl << "~ Program Execution Complete ~" << endl << endl;
		sim.printMemory();

		/*
		//Ask for another program.
		cout << "Would you like to enter another program? (Y/N): ";
		cin >> again;
		cout << endl << endl;
		if (again == 'Y' || again == 'y') {
			sim.clearProgram();
			memLocation = 0;
			again = 'N';
			continue;
		}
		else
			cout << "Program Done.";
		*/
		++end;
		cout << "Program Done.";
	}
}
/*
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