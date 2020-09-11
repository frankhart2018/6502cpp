#ifndef CPP_6502_TOKENTYPE
#define CPP_6502_TOKENTYPE

typedef enum {
    // OpCodes
    LDA, ADC, CMP, BEQ, JMP, STA, JSR,

    // Standard I/O
    INPUT, OUTPUT,

    // Operators
    SEMICOLON, POUND, DOLLAR,

    // Misc
    LABEL, NUMBER
} TokenType;

#endif
