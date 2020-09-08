#include <iostream>

#include "lexical_analysis.hpp"

int main() {
  std::cout << is_opcode("CMP") << std::endl;
  std::cout << is_opcode("MDA") << std::endl;

  Token t = make_token("CMP", is_opcode("CMP"), 1);

  std::cout << t.get_token() << " " << t.get_type() << " " << t.get_line() << std::endl;
}
