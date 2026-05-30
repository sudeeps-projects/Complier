#include "assembler.h";
/*
LDA 5
STA 100

loop:

LDM 100
OUT

LDB 1
SUB

STA 100

JNZ loop

HLT*/
int main() {
	cout << "Hello World" << endl;
	cout << ".";
	CPU cpu;
	cpu.init();
	cpu.print_CPU_state();

	cpu.writeMemory("LDA 5");
	cpu.writeMemory("STA 100");
	cpu.writeMemory("loop");
	cpu.writeMemory("LDM 100");
	cpu.writeMemory("OUT");
	cpu.writeMemory("LDB 1");
	cpu.writeMemory("SUB");
	cpu.writeMemory("STA 100");
	cpu.writeMemory("JNZ loop");
	cpu.run();
	cpu.print_CPU_state();

	return 0;
}