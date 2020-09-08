exec:
	@make 6502_cpp_exec

6502_cpp_exec: src/lexical_analysis.cpp emulator.cpp
	@g++ -std=c++11 -o 6502 src/lexical_analysis.cpp emulator.cpp
