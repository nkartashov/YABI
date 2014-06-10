#include "interpreter.h"

Interpreter::Interpreter():
	m_current(0),
	m_source_position(0) {}


void Interpreter::next() {
	++m_current;
}

void Interpreter::prev() {
	--m_current;
}

void Interpreter::add() {
	++m_memory[m_current];
}

void Interpreter::sub() {
	--m_memory[m_current];
}

void Interpreter::put() {
	printf("%c", m_memory[m_current]);
}

void Interpreter::get() {
	scanf("%c", m_memory + m_current);
}

void Interpreter::forward_jump(std::string const& source) {
	if (m_memory[m_current] == 0) {
    int depth = 0;
    while (m_source_position < (source.size() - 1)) {
      ++m_source_position;
      char current_char = source[m_source_position];
      if (current_char == '[') {
        ++depth;
      } else if (current_char == ']') {
        if (depth == 0) {
          ++m_source_position;
          break;
        }
        --depth;
      }
    }
	}
}

void Interpreter::backward_jump(std::string const& source) {
	if (m_memory[m_current] != 0) {
    int depth = 0;
		while (m_source_position > 0) {
      --m_source_position;
      char current_char = source[m_source_position];
      if (current_char == ']') {
        ++depth;
      } else if (current_char == '[') {
        if (depth == 0) {
          break;
        }
        --depth;
      }
    }
	}
}

void Interpreter::handle_char(std::string const& source) {
	char symbol = source[m_source_position];
	switch (symbol) {
		case '>':
			next();
			break;
			
		case '<':
			prev();
			break;

		case '+':
			add();
			break;

		case '-':
			sub();
			break;

		case '.':
			put();
			break;

		case ',':
			get();
			break;

		case '[':
			forward_jump(source);
			break;

		case ']':
			backward_jump(source);
			break;
	}
}

void Interpreter::interpret(std::string const& source) {
	while (m_source_position < source.size()) {
		handle_char(source);
		++m_source_position;
	}
	printf("\n");
}
