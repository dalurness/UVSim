#pragma once
class UserProgram
{
	const int SIZE_OF_MEMORY = 1000;
public:
	UserProgram() {};
	void cliProgramLoad(Simulator* sim);
	void fileProgramLoad(Simulator* sim);
};

