#pragma once

#include "Date.h"
#include "enums.h"

using namespace std;


class Node {
private:
    /* data */
public:
    Node(/* args */);

    virtual bool Evaluate(Date date, string condition) const = 0;
};


class EmptyNode : public Node {
private:

public:
    virtual bool Evaluate(Date date, string condition) const override;
};


class LogicalOperationNode : public Node {
private:
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
    LogicalOperation op_;

public:
    LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> lhs, shared_ptr<Node> rhs);
    virtual bool Evaluate(Date date, string condition) const override;
};


class DateComparisonNode : public Node {
private:
    const Comparison op_; // операция сравнения
    const Date date_; // дата-референс
    
public:
    DateComparisonNode();
    DateComparisonNode(Comparison cmp, Date date);
    // ~DateComparisonNode();
    virtual bool Evaluate(Date date, string condition) const override;
};


class EventComparisonNode : public Node {
private:
    const Comparison op_; // операция сравнения
    const string event_; // событие-референс

public:
    EventComparisonNode();
    EventComparisonNode(Comparison cmp, const string& event);
    virtual bool Evaluate(Date date, string condition) const override;
    // ~EventComparisonNode();
};
