#include "assembler.h";

int main() {
	cout << "Hello World" << endl;
	cout << ".";
	CPU cpu;
	cpu.init();
	cpu.print_CPU_state();

	cpu.writeMemory("LDA 72");
	cpu.writeMemory("OUT");
	cpu.writeMemory("LDA 73");
	cpu.writeMemory("OUT");
	cpu.writeMemory("LDA 10");
	cpu.writeMemory("OUT");
	cpu.writeMemory("HLT");
	cpu.run();
	cpu.print_CPU_state();

	return 0;
}