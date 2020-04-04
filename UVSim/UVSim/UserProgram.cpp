#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "simulator.h"
#include "UserProgram.h"

void UserProgram::cliProgramLoad(Simulator* sim) {
	int memLocation = 0;
	std::string cmd;

	std::cout << "| Please enter your program one instruction at a time.   |" << std::endl;
	std::cout << "| The memory location of your command will be displayed. |" << std::endl;
	std::cout << "| Enter /0 to stop entering your program.                |" << std::endl;
	std::cout << "==========================================================" << std::endl;

	while (true) {
		if (memLocation < 10) {
			std::cout << "0" << memLocation << " : ";
		}
		else {
			std::cout << memLocation << " : ";
		}
		std::cin >> cmd;
		if (cmd == "/0") {
			break;
		}

		//Exception handling for loading commands into memory.
		try {
			sim->loadCommandIntoMemory(cmd);
		}
		catch (const std::exception e1) {
			if (e1.what() == "Memory overflow") {
				std::cout << "An exception occurred: " << e1.what() << std::endl << "Please re-enter program: " << std::endl << std::endl;
				sim->clearProgram();
				memLocation = 0;
				continue;
			}
			else {
				std::cout << "An exception occurred: " << e1.what() << std::endl << "Please re-enter instruction: " << std::endl;
				sim->clearLast();
				//sim.clearProgram();
				//--memLocation;
				continue;
			}
		}


		//sim.loadCommandIntoMemory("+1002);
		memLocation++;
	}

	std::cout << "~ Program Loading Complete ~" << std::endl << std::endl;
	std::cout << "~ Begin Executing Program ~" << std::endl;
};

void UserProgram::fileProgramLoad(Simulator* sim) {
	bool invalidFile = true;
	std::ifstream inFS;
	while (invalidFile) {
		std::string filename;
		std::cout << "Please enter the name of the program file: ";
		std::cin >> filename;
		inFS.open(filename);
		if (!inFS.is_open()) {
			if (filename == "q") {
				exit(0);
			}
			std::cout << std::endl << std::endl;
			std::cout << "Invalid file name given. Please insert a valid file." << std::endl << std::endl;
			continue;
		}
		invalidFile = false;
	}

	std::string nextInstruction;
	while (inFS.get() != EOF) {
		nextInstruction.clear();
		inFS >> nextInstruction;
		sim->loadCommandIntoMemory(nextInstruction);
	}

	
};