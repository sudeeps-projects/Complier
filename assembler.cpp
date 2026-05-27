#include "assembler.h";



void CPU::init() {
	regA = 0;
	regB = 0;
	pc = 0;
	memIndx = 0;
	zero_flag = false;
	carry_flag = false;
	hlt = false;
}

void CPU::run() {
	while (hlt != true) {
		switch (ram[pc]) {
		case LDA:
			regA = ram[pc + 1];
			pc = pc + 2;
			break;
		case LDB:
			regB = ram[pc + 1];
			pc = pc + 2;
			break;
		case ADD:
			regA = regA + regB;
			pc++;
			break;
		case SUB:
			regA = regA - regB;
			pc++;
			break;
		case OUT:
			cout << regA;
			pc++;
			break;
		case HLT:
		default:
			hlt = true;
		}
	
	}

	
}

void CPU::print_CPU_state() {
	

	cout << "PC; " << static_cast<int>(pc)
	 << " regA; " << static_cast<int>(regA)

	 << " regB; " << static_cast<int>(regB)
	<< " CF; " << carry_flag
		<< " ZF; " << zero_flag
		<< "ram @ pc" << static_cast<int>(ram[pc]) 
		<< "Memory Index" << static_cast<int>(memIndx) << endl;


}

uint8_t CPU::readMemory(uint8_t address) {
	return ram[address];
}

void CPU::writeMemory(uint8_t address, uint8_t value) {
	
	ram[address] = value;
}

void CPU::writeMemory(string str) {
	stringstream ss(str);
	int value;
	string instruction;
	ss >> instruction;
	
	if (instruction == "LDA") {
		ss >> value;
		ram[memIndx++] = LDA;
		ram[memIndx++] = static_cast<uint8_t>(value);

	}
	else if (instruction == "LDB") {
		ss >> value;
		ram[memIndx++] = LDB;
		ram[memIndx++] = static_cast<uint8_t>(value);
	}
	else if (instruction == "ADD") {
		ram[memIndx++] = 2;
	}
	else if (instruction == "SUB") {
		ram[memIndx++] = 3;
	}
	else if (instruction == "STA") {
		ss >> value;
		ram[value] = regA;
		// TODO error checking above or below ram size
	}
	else if (instruction == "LDM") {
		ss >> value;
		regA = ram[value];
	}
	else if (instruction == "HLT") {
		ram[memIndx++] = 4;
	}
	else if (instruction == "OUT") {
		ram[memIndx++] = OUT;
	}
	
	else {
		ram[memIndx++] = 99;
		cerr << "Bad Instruction!" << endl;
	}
	

	
}