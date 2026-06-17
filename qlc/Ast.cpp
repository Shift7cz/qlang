# include "Ast.hpp"

#include <iostream>

void Ast::print() { // helper print function, debugging.
    if (!root) {
        std::cout << "AST is empty.\n";
        return;
    }
    std::cout << "--- AST Structure ---\n";
    printNode(root.get(), 0);
}

void Ast::printNode(Node* node, int indent) { // helper print function, debugging.
    if (!node) return;

    // Create indentation string (2 spaces per level)
    std::string spaces(indent * 2, ' ');

    switch (node->type) {
        case NodeType::Func: {
            // 1. Cast to FuncNode to access unique features (.identifier and .body)
            auto func = static_cast<FuncNode*>(node);
            std::cout << spaces << "[Function] -> name: '" << func->identifier << "'\n";

            // 2. Recursively print all statements inside the function body
            for (const auto& child : func->body) {
                printNode(child.get(), indent + 1); // Increase indent for children!
            }
            break;
        }
        case NodeType::RetInt: {
            auto ret = static_cast<RetIntNode*>(node);
            std::cout << spaces << "[Return Statement] -> value: " << ret->value << "\n";
            break;
        }
    }
}
