#pragma once
#include <memory>
#include "Date.h"
#include "condition_parser.h"

using namespace std;

class Node {
private:
    /* data */
public:
    Node(/* args */);
    ~Node();
    virtual bool Evaluate(Date date, string condition) const = 0;
};


class EmptyNode : public Node {
private:

public:
    virtual bool Evaluate(Date date, string condition);
};


class LogicalOperationNode : public Node {
private:
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
    LogicalOperation op_;

public:
    LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> lhs, shared_ptr<Node> rhs);
    virtual bool Evaluate(Date date, string condition);
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
