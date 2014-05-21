#include <fstream>

#include "interpreter.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	std::string source_path(argv[1]);
	std::ifstream ifs(source_path);
	ifs.seekg(0, ifs.end);
	size_t source_length = ifs.tellg();
	ifs.seekg(0, ifs.beg);
	char* source_mem = new char[source_length];
	ifs.read(source_mem, source_length);
	std::string source(source_mem, source_length);
	delete source_mem;
	Interpreter interpreter;
	interpreter.interpret(source);
	return 0;
}
