#include "ASTNode.h"

#include "../../parsing/XMLNode.h"
#include "node_types.h"

namespace apertium {
namespace xml2cpp {
ASTNode::ASTNode() {
}

ASTNode::~ASTNode() {
  for (ASTNode *child : children_) {
    delete child;
  }
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

void ASTNode::AddChild(ASTNode *child) {
  children_.push_back(child);
}

void ASTNode::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
}

ASTNode *ASTNode::FromXMLNode(const XMLNode& xml_node) {
  ASTNode *node = UninitializedByTag(xml_node.get_tag());
  if (node != NULL) {
    node->set_tag(xml_node.get_tag());
    node->set_line_no(xml_node.get_line_no());
    node->Initialize(xml_node.get_attrs());
  }
  return node;
}

ASTNode *ASTNode::UninitializedByTag(const std::wstring& tag) {
  if (tag == L"*") return new ASTNode_Root();
  if (tag == L"transfer") return new ASTNode_Transfer();
  return new ASTNode_Undefined();
}
}; // namespace xml2cpp
}; // namespace apertium
