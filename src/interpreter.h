#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#define DEBUG0

#include <string>

class Interpreter {
	public:
		Interpreter();

		void interpret(std::string const& source);

		static const int MAX_MEMORY = 30000; 
	
	private:
		void next();
		void prev();
		void add();
		void sub();
		void put();
		void get();
		void forward_jump(std::string const& source);
		void backward_jump(std::string const& source);

		void handle_char(std::string const& source);

		char m_memory[MAX_MEMORY];
		int m_current;
		size_t m_source_position;

};

#endif /* end of include guard */
