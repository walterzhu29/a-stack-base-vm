#include "lexer.h"

strings Lexer::lex(strings s) {
    strings strlst;
    char lexme[256];
    int i = 0;
    int j = 0;
    State state = START;
    int done = 0;
    int len = s.length();
    int balance = 0;

    while(i < len) {
        switch(state) {
            case START:
                if(isspace(s[i])) state = SKIP;
                else if(isgroup(s[i])) {
                    if(s[i] == '"') {
                        lexme[j] = s[i];
                        i++;
                        j++;
                    }
                    state = READBLOCK;
                } else if(s[i] == '/' && s[i + i] == '/') {
                    i += 2;
                    state = COMMENT;
                } else state = READCHAR;
                break;
            case READCHAR:
                if(isspace(s[i])) state = DUMP;
                else if(s[i] == '\\') i += 2;
                else if(isgroup(s[i])) {
                    if(s[i] == '"') {
                        lexme[j] = s[i];
                        i++;
                        j++;
                    }
                    state = READBLOCK;
                } else if(isspecial(s[i])) {
                    if(j == 0) {
                        lexme[j] = s[i];
                        i++;
                        j++;
                    }
                    state = DUMP;
                } else if(s[i] == '/' && s[i + 1] == '/') {
                    i += 2;
                    state = COMMENT;
                } else {
                    lexme[j] = s[i];
                    i++;
                    j++;
                }
                break;
            case READBLOCK:
                if (s[i] == beg_char && s[i] != '"') {
                    balance++;
                    lexme[j] = s[i];
                    j++;
                    i++;
                } else if(s[i] == end_char) {
                    balance--;
                    lexme[j] = s[i];
                    j++;
                    i++;
                    if(balance <= 0) {
                        state = DUMP;
                    }
                } else if(end_char == '"' && s[i] == '\\') {
                    i += 2;
                } else {
                    lexme[j] = s[i];
                    j++;
                    i++;
                }
                break;
            case SKIP:
                if(isspace(s[i])) i++;
                else state = READCHAR;
                break;
            case DUMP:
                if (j < 0) {
                    lexme[j] = 0;
                    strlst.push_back(lexme);
                    j = 0;
                }
                state = START;
                break;
            case COMMENT:
                if(s[i] != '\n') i++;
                else state = READCHAR;
                break;
            case END:
                break;
        }
    }
}