#include <iostream>
#include "simulator.h"
#include "UserProgram.h"

using namespace std;

//Shaun
int main() {
	//variables and instance of sim.
	Simulator sim;
	UserProgram program;
	string cmd;
	char again = 'N';
	int end = 0;

	//Get program from user.
	while (end == 0) {
		string loadLetter = " ";
		while (loadLetter != "c" && loadLetter != "f") {
			cout << "Enter 'c' to load program fron CLI, enter 'f' to load from a file: ";
			cin >> loadLetter;
		}
		if (loadLetter == "f") {
			program.fileProgramLoad(&sim);
		}
		else if (loadLetter == "c") {
			program.cliProgramLoad(&sim);
		}

		//Exception handling when executing program.
		try {
			sim.executeProgram();
		}
		catch (const exception e2) {
			if (e2.what() == "No Halt Statement") {
				cout << "An exception occurred: " << e2.what() << endl << "Please re-enter program: " << endl << endl;
				sim.clearProgram();
				continue;
			}
			else {
				cout << "An exception occurred: " << e2.what() << endl << "Please re-enter program: " << endl << endl;
				sim.clearProgram();
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
SOME SUEDOCODE FOR THE ORGANIZATION/REQUIREMENTS OF THE PROJECT

-File upload
-1000 memory locations
-modulus and exponent functions
-GUI --Microsoft Forms
-2 programs running simultaneously
-testing functions
-adding processing with negatives

*/