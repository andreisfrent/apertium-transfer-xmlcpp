#include "ASTNode.h"

#include <iostream>

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
  std::wcerr << L"Initialize() unimplemented for " << tag_ << "." << std::endl;
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
  if (tag == L"action") return new ASTNode_Action();
  if (tag == L"attr-item") return new ASTNode_AttrItem();
  if (tag == L"cat-item") return new ASTNode_CatItem();
  if (tag == L"clip") return new ASTNode_Clip();
  if (tag == L"def-attr") return new ASTNode_DefAttr();
  if (tag == L"def-cat") return new ASTNode_DefCat();
  if (tag == L"def-var") return new ASTNode_DefVar();
  if (tag == L"let") return new ASTNode_Let();
  if (tag == L"lit-tag") return new ASTNode_LitTag();
  if (tag == L"lu") return new ASTNode_Lu();
  if (tag == L"out") return new ASTNode_Out();
  if (tag == L"pattern") return new ASTNode_Pattern();
  if (tag == L"pattern-item") return new ASTNode_PatternItem();
  if (tag == L"*") return new ASTNode_Root();
  if (tag == L"rule") return new ASTNode_Rule();
  if (tag == L"section-def-attrs") return new ASTNode_SectionDefAttrs();
  if (tag == L"section-def-cats") return new ASTNode_SectionDefCats();
  if (tag == L"section-def-vars") return new ASTNode_SectionDefVars();
  if (tag == L"section-rules") return new ASTNode_SectionRules();
  if (tag == L"transfer") return new ASTNode_Transfer();
  return NULL;
}
}; // namespace xml2cpp
}; // namespace apertium
