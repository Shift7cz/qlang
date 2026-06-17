#pragma once

#include <vector>
#include <memory>

enum class NodeType {
    Unassigned,

    Func,
    RetInt
};

class Node {
public:
    NodeType type;

    Node(NodeType t) : type(t) {}

    virtual ~Node() = default;
};

class UnassignedNode : public Node { // used for declaring before assignment.
public:
    UnassignedNode() : Node(NodeType::Unassigned) {}
};

class FuncNode : public Node {
public:
    std::string_view identifier;
    std::vector<std::unique_ptr<Node>> body;

    FuncNode() : Node(NodeType::Func) {}
};

class RetIntNode : public Node {
public:
    int value;

    RetIntNode() : Node(NodeType::RetInt) {}
};