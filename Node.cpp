#include "Node.h"
#include "condition_parser.h"

Node::Node(){};
bool EmptyNode::Evaluate(Date date, string condition) {return true;}

// LogicalOperationNode
LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, 
        shared_ptr<Node> lhs, shared_ptr<Node> rhs) : 
        op_(op), left_{lhs}, right_{rhs} {}

bool LogicalOperationNode::Evaluate(Date date, string condition) {
    bool left_eval{left_->Evaluate(date, condition)};
    bool right_eval{right_->Evaluate(date, condition)};
    switch (op_)
    {
    case LogicalOperation::And :
        return left_eval && right_eval;
        break;
    
    case LogicalOperation::Or :
        return left_eval || right_eval;
        break;
    
    default:
        return true;
        break;
    }
}
// /LogicalOperationNode

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
