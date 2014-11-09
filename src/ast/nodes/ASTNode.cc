#include <apertium_xml2cpp.h>
#include <iostream>

namespace apertium {
namespace xml2cpp {
ASTNode::ASTNode(const XMLNode *xml_node) {
  set_line_no(xml_node->get_line_no());
  set_tag(xml_node->get_tag());
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
