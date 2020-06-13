#pragma once
#include "Date.h"

class Node {
private:
    /* data */
public:
    Node(/* args */);
    ~Node();
    virtual bool Evaluate(Date date, std::string condition) const = 0;
};


class EmptyNode : public Node {

};

class LogicalOperationNode : public Node {

};

class DateComparisonNode : public Node {
private:

public:
    DateComparisonNode();
    DateComparisonNode(Comparison cmp, Date date);
    ~DateComparisonNode();
};

class EventComparisonNode : public Node {
    EventComparisonNode();
    EventComparisonNode(Comparison cmp, const string& event);
    ~EventComparisonNode();
};
