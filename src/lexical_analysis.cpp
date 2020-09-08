#include <string>
#include <map>

#include "../includes/lexical_analysis.hpp"
#include "../includes/token.hpp"


int is_opcode(std::string token) {
  std::map<std::string, TokenType> opcode_to_tokentype = {{"LDA", LDA}, {"ADC", ADC}, {"CMP", CMP}, {"BEQ", BEQ}, {"JMP", JMP}, {"STA", STA}};
  std::map<std::string, TokenType>::iterator it;

  for(it = opcode_to_tokentype.begin(); it != opcode_to_tokentype.end(); it++) {
    if(it->first == token)
      return it->second;
  }

  return -1;
}

Token make_token(std::string token, int type, int line) {
  Token t(token, type, line);

  return t;
}
