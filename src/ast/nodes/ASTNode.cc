#include "ASTNode.h"

#include <iostream>

namespace apertium {
namespace xml2cpp {
ASTNode::ASTNode(const XMLNode *xml_node) {
  // TODO
}

ASTNode::~ASTNode() {
}

int ASTNode::get_line_no() const {
  return line_no_;
}

void ASTNode::set_line_no(int line_no) {
  line_no_ = line_no;
}

const std::wstring& ASTNode::get_tag() const {
  return tag_;
}

void ASTNode::set_tag(const std::wstring& tag) {
  tag_ = tag;
}
} // namespace xml2cpp
} // namespace apertium
