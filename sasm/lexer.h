#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>

using namespace std;

typedef uint8_t byte;
typedef vector<string> strings;

enum State: byte {
    START,
    READCHAR,
    READBLOCK,
    SKIP,
    DUMP,
    COMMENT,
    END
}

class Lexer {
    bool isspace(char c);
    bool isspecial(char c);
    bool isgroup(char c);
    char end_char, beg_char;
    public:
    strings lex(string s);
}