#include <iostream>
#include <string>
#include <stdexcept>
#include "simulator.h" 

using namespace std;


void Simulator::loadCommandIntoMemory(std::string command) {
	if (this->memory.size() == SIZE_OF_MEMORY) {
		throw std::out_of_range("Memory overflow");
	}
	if (command.size() != 5 ) {
		throw std::invalid_argument("Command must be a signed four-digit decimal number (+1234 or -5678)");
	}
	char sign = command[0];
	std::string com = command.substr(1, 5);
	for (char x : com) {
		if (!isdigit(x)) {
			throw std::invalid_argument("Command must be a signed four-digit decimal number (+1234 or -5678)");
		}
	}
	switch (sign) {
	case '-' :
		if (com == "9999")
			return;
		this->memory.push_back("1" + com);
		break;
	case '+' : 
		this->memory.push_back("0" + com);
		break;
	default :
		throw std::invalid_argument("Command must be a signed four-digit decimal number (+1234 or -5678)");
	}
}

/***Shaun & Dallin***/
void Simulator::printMemory() {
	//Print Register contents.
	std::wcout << "REGISTERS: " << std::endl;
	std::cout << "Accumulator: " << this->Accumulator << std::endl;
	std::cout << "Instruction Counter: " << this->InstructionCounter << std::endl;
	std::cout << "Instruction Register: " << this->InstructionRegister << std::endl;
	std::cout << "Operation Code: " << this->OperationCode << std::endl;
	std::cout << "Operand: " << this->Operand << std::endl << std::endl;

	//Print Memory Table (10x10).
	std::cout << "MEMORY: " << std::endl;

	//Fill vector with emtpy data to fill table.
	for (int i = this->memory.size(); i < SIZE_OF_MEMORY; i++) {
		this->memory.push_back("00000");
	}
	std::cout << "  ";
	for (int i = 0; i < 10; i++) {
		std::cout << "     ";
		if (i < 10)
			std::wcout << "0" << i;
	}

	int j = 0;
	for (int i = 0; i < this->memory.size(); ++i) {
		if (i % 10 == 0 /*&& i != 0*/) {
			std::cout << std::endl;
			if (i < 10)
				std::wcout << "0";
			std::cout << j << "  ";
			j += 10;
		}
		//else if (i % 5 == 0 && i != 0)
			//std::cout << "   ";
		std::cout << this->memory.at(i) << "  ";
	}
	std::wcout << std::endl << std::endl;
}

void Simulator::executeProgram() {
	while (true) {
		std::string nextCommand = this->memory.at(this->InstructionCounter);
		//if (nextCommand.substr(0, 3) == ("0" + std::to_string(HALT)))
		//	return;
		int memoryLocation = stoi(nextCommand.substr(3, 5));
		//check if command is positive or negative
		switch (nextCommand[0]) {
		case '1':
			//do some negative command ish
			break;
		case '0':
			//do some positive command ish

			switch (stoi(nextCommand.substr(1, 2))) {
			case READ:
				this->read(memoryLocation);
				break;
			case WRITE:
				this->write(memoryLocation);
				break;
			case LOAD:
				this->load(memoryLocation);
				break;
			case STORE:
				this->store(memoryLocation);
				break;
			case ADD:
				this->add(memoryLocation);
				break;
			case SUBTRACT:
				this->subtract(memoryLocation);
				break;
			case DIVIDE:
				this->divide(memoryLocation);
				break;
			case MULTIPLY:
				this->multiply(memoryLocation);
				break;
			case BRANCH:
				this->branch(memoryLocation);
				break;
			case BRANCHNEG:
				this->branchNeg();
				break;
			case BRANCHZERO:
				this->branchZero();
				break;
			case HALT:
				this->printOutDetails();
				return;
				break;
			case MEMDUMP:
				this->memDump();
				break;
			case BREAK:
				this->breakLoop();
				break;
			case CONTINUE:
				this->continueLoop();
				break;
			default:
				throw std::logic_error("Invalid command found in memory at location: " + std::to_string(this->InstructionCounter));
			}
			break;
		default:
			throw std::invalid_argument("First digit in each word must be a 1 or 0(- or +)");
		}
		this->InstructionCounter++;
		if (this->InstructionCounter > this->memory.size()) {
			throw std::out_of_range("No Halt Statement");
		}
	}
}

void Simulator::read(int memoryLocation) {
	bool isNumber = false;
	std::string stringNumber;
	while (!isNumber) {
		std::cout << "Please enter two digit number to insert into location " << memoryLocation << ": ";
		std::cin >> stringNumber;

		isNumber = true;
		for (char x : stringNumber)
			if (!isdigit(x)) { isNumber = false; };
		if (isNumber && stoi(stringNumber) > 99)
			std::cout << std::endl << "Number needs to be two digits" << std::endl << std::endl;
	}
	//insert number into memory location
	string newValue = this->memory.at(memoryLocation);
	newValue[3] = stringNumber[0];
	newValue[4] = stringNumber[1];
	this->memory.at(memoryLocation) = newValue;
}

void Simulator::load(int memoryLocation) {
	this->Accumulator = stoi(this->memory.at(memoryLocation));
}


//Write word from memoryLocation to console
void Simulator::write(int memoryLocation) {
	cout << this->memory.at(memoryLocation);
	cout << endl;
}