#include <iostream>
#include <vector>
#include <fstream>

#include "includes/lexical_analysis.hpp"
#include "includes/token.hpp"

std::string read_source_code(std::string filepath) {
  std::ifstream file(filepath);
  std::string source_code;

  file.seekg(0, std::ios::end);
  source_code.reserve(file.tellg());
  file.seekg(0, std::ios::beg);

  source_code.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

  return source_code;
}

int main(int argc, char *argv[]) {
  std::string source_code = read_source_code(argv[1]);

  std::vector<Token> tokens = lexical_analysis(source_code);

  for(int i=0; i<tokens.size(); i++) {
    std::cout << tokens[i].get_token() << " " << tokens[i].get_type() << " " << tokens[i].get_line() << std::endl;
  }

  return 0;
}
