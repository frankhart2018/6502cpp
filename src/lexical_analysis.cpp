#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <iostream>

#include "../includes/lexical_analysis.hpp"
#include "../includes/token.hpp"


int is_opcode(std::string token) {
  std::map<std::string, TokenType> opcode_to_tokentype = {{"LDA", LDA}, {"ADC", ADC}, {"CMP", CMP},
  {"BEQ", BEQ}, {"JMP", JMP}, {"STA", STA}, {"JSR", JSR}, {"INPUT", INPUT}};

  std::map<std::string, TokenType>::iterator it;

  for(it = opcode_to_tokentype.begin(); it != opcode_to_tokentype.end(); it++) {
    if(it->first == token)
      return it->second;
  }

  return LABEL;
}

Token make_token(std::string token, int type, int line) {
  Token t(token, type, line);

  return t;
}

std::vector<Token> lexical_analysis(std::string source_code) {
  int line = 1;
  std::vector<Token> tokens;

  for(int i=0; i<source_code.length(); i++) {
    if(isalpha(source_code[i])) {
      std::string opcode_or_label = "";
      while(isalpha(source_code[i])) {
        opcode_or_label += source_code[i];
        i++;
      }
      i--;

      tokens.push_back(make_token(opcode_or_label, is_opcode(opcode_or_label), line));
    }
    else if(isdigit(source_code[i])) {
      std::string number = "";
      while(isdigit(source_code[i])) {
        number += source_code[i];
        i++;
      }
      i--;

      tokens.push_back(make_token(number, NUMBER, line));
    }
    else if(source_code[i] == ';') {
      tokens.push_back(make_token(";", SEMICOLON, line));
    }
    else if(source_code[i] == '#') {
      tokens.push_back(make_token("#", POUND, line));
    }
    else if(source_code[i] == '$') {
      tokens.push_back(make_token("$", DOLLAR, line));
    }
    else if(source_code[i] == '\n') {
      line++;
    }
  }

  return tokens;
}
