#pragma once

#include <memory>
#include <iostream>
#include "enums.h"

using namespace std;

class Node;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
