#pragma once
#include "Date.h"

class Node
{
private:
    /* data */
public:
    Node(/* args */);
    ~Node();
    bool Evaluate(Date date, std::string condition);
};


class EmptyNode : public Node {

};

class LogicalOperationNode : public Node {

};

class DateComparisonNode : public Node {

};

class EventComparisonNode : public Node {

};
