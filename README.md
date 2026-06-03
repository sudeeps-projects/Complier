# Minerva-8

This project is the demonstration of how a 8-bit CPU actually works in computers. In this project, there has been created an assembler which parses lines from memory (RAM) and generates byte code that is read by the computer. An assembler language serves as the go-between from RAM to byte code. 

RAM of 256 Bytes is used in this project to store instructions and data. A byte is 8 bits, and can hold numbers less than 2^8. 

Fetch Unit uses a program counter to fetch the opp-codes from RAM.

The Decoding Unit iterates through the opp-codes fetched from RAM, and parses the instructions and data.

The Execution Unit stores data into registers and flags, and loads and stores from memory as well as outputing to the console.

The Supported Instruction set so far: 

enum oppCode {
	LDA = 0,
	LDB,
	LDM,
	ADD,
	SUB,
	STA,
	OUT,
	JNZ,
	JZ,
	JMP,
	HLT
};
