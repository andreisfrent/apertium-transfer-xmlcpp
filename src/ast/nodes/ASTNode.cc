#include "ASTNode.h"

#include "../../parsing/XMLNode.h"
#include "node_types.h"

namespace apertium {
namespace xml2cpp {
ASTNode::ASTNode() {
}

ASTNode::~ASTNode() {
}

ASTNode* ASTNode::FromXMLNode(const XMLNode& xml_node) {
  return NULL;
}
}; // namespace xml2cpp
}; // namespace apertium
