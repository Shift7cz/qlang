#include "Parser.hpp"

void Parser::advance() {
    currentToken = lexer.nextToken();
}

void Parser::parse() {
    auto mainFunc = std::make_unique<FuncNode>();
    mainFunc->identifier = "main";

    auto ret = std::make_unique<RetIntNode>();
    ret->value = 67;

    mainFunc->body.push_back(std::move(ret));

    ast.root = std::move(mainFunc);
}
