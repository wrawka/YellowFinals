#pragma once

#include <memory>
#include <iostream>
#include "Node.h"

using namespace std;


enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual,
};

enum class LogicalOperation {
  Or,
  And,
};

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
