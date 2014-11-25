#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Choose::Choose(const XMLNode *xml_node)
    : Statement(xml_node), otherwise_(NULL) {
  ExtractMultipleWhen(xml_node);
  ExtractSingleOtherwise(xml_node);
}

void Choose::ExtractMultipleWhen(const XMLNode *xml_node) {
  Error::Assert(
      xml_node->GetChildrenByTag(L"when").size() >= 1,
      *xml_node, "No when clause");

  for (const XMLNode *xml_when : xml_node->GetChildrenByTag(L"when")) {
    HandleXMLWhen(xml_when);
  }
}

void Choose::ExtractSingleOtherwise(const XMLNode *xml_node) {
  const std::vector<XMLNode*>& otherwise_nodes =
      xml_node->GetChildrenByTag(L"otherwise");

  Error::AssertFalse(
      otherwise_nodes.size() > 1,
      *xml_node, "Multiple otherwise clauses.");

  if (otherwise_nodes.size() > 0) {
    otherwise_ = new CodeBlock(otherwise_nodes.at(0));
  }
}

void Choose::HandleXMLWhen(const XMLNode *xml_node) {
  Error::Assert(
      xml_node->get_children().size() >= 1,
      *xml_node, "No children.");
  Error::Assert(
      xml_node->get_children().at(0)->get_tag() == L"test",
      *xml_node, "Missing test.");

  Condition *test = HandleXMLTest(xml_node->get_children().at(0));
  CodeBlock *code_block = new CodeBlock(
      xml_node,
      xml_node->get_children().begin() + 1,
      xml_node->get_children().end());

  cases_.push_back(std::make_pair(test, code_block));
}

Condition* Choose::HandleXMLTest(const XMLNode *xml_node) {
  Error::Assert(
      xml_node->get_children().size() == 1,
      *xml_node, "Should have exactly one child.");
  return new Condition(xml_node->get_children().at(0));
}

Choose::~Choose() {
  if (otherwise_) {
    delete otherwise_;
  }

  for (auto& it : cases_) {
    delete it.first;
    delete it.second;
  }
}

void Choose::SemanticCheck(const CompilationContext *ctx) const {
  for (const auto& it : cases_) {
    it.first->SemanticCheck(ctx);
    it.second->SemanticCheck(ctx);
  }
  if (otherwise_) {
    otherwise_->SemanticCheck(ctx);
  }
}
} // namespace xml2cpp
} // namespace apertium
