#include "Node.h"
#include "condition_parser.h"



bool Node::Evaluate(Date date, string condition) const {}

bool EmptyNode::Evaluate(Date date, string condition) {return true;}

// DateComparisonNode
DateComparisonNode::DateComparisonNode(Comparison cmp, Date date) : op_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(Date date, string condition) {
    switch (op_)
    {
    case Comparison::Less :
        return date < date_;
        break;
    
    case Comparison::LessOrEqual :
        return !(date_ < date);
        break;
    
    case Comparison::Greater :
        return date_ < date;
        break;
    
    case Comparison::GreaterOrEqual :
        return !(date < date_);
        break;
    
    case Comparison::Equal :
        return date == date_;
        break;
    
    case Comparison::NotEqual :
        return !(date == date_);
        break;
    
    default:
        return true;
        break;
    }
}
// /DateComparisonNode

// EventComparisonNode
EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event) : op_(cmp), event_(event) {}

bool EventComparisonNode::Evaluate(Date date, string condition) {
    switch (op_)
    {
    case Comparison::Equal:
        return event_ == condition;
        break;
    
    case Comparison::NotEqual:
        return !(event_ == condition);
        break;
    
    default:
        return false;
        break;
    }
}
//  /EventComparisonNode
