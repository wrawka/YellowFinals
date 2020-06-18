#pragma once
#include "Date.h"

class Node {
private:
    /* data */
public:
    Node(/* args */);
    ~Node();
    virtual bool Evaluate(Date date, string condition) const = 0;
};


class EmptyNode : public Node {
    virtual bool Evaluate(Date date, string condition);
};

class LogicalOperationNode : public Node {

};

class DateComparisonNode : public Node {
private:
    const Comparison op_; // операция сравнения
    const Date date_; // дата-референс
    
public:
    DateComparisonNode();
    DateComparisonNode(Comparison cmp, Date date);
    ~DateComparisonNode();
    virtual bool Evaluate(Date date, string condition);
};

class EventComparisonNode : public Node {
private:
    const Comparison op_; // операция сравнения
    const string event_; // событие-референс
    virtual bool Evaluate(Date date, string condition);

public:
    EventComparisonNode();
    EventComparisonNode(Comparison cmp, const string& event);
    ~EventComparisonNode();
};
