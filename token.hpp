#ifndef CPP_6502_TOKEN
#define CPP_6502_TOKEN

#include "tokentype.hpp"

class Token {
private:
  std::string token;
  int type;
  int line;
public:
  Token(std::string token, int type, int line) {
    this->token = token;
    this->type = type;
    this->line = line;
  }

  std::string get_token() {
    return this->token;
  }

  int get_type() {
    return this->type;
  }

  int get_line() {
    return this->line;
  }
};

#endif
