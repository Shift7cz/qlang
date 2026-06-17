#pragma once

#include "Lexer.hpp"
#include "Ast.hpp"

class Parser {
private:
    Lexer& lexer;
    Token currentToken;

    void advance();
public:
    Ast ast;

    Parser(Lexer& lexer) : lexer(lexer) {}

    void parse();
};
