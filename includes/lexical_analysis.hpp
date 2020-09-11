#ifndef CPP_6502_LEXICAL_ANALYSIS
#define CPP_6502_LEXICAL_ANALYSIS

#include <vector>

#include "token.hpp"

int is_opcode(std::string);

Token make_token(std::string, int, int);

std::vector<Token> lexical_analysis(std::string);

#endif
