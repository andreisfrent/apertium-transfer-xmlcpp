#include <apertium_xml2cpp.h>
#include <string>
#include <vector>

namespace apertium {
namespace xml2cpp {
ASTNode_Rules::ASTNode_Rules(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"rule") {
      HandleRuleDefinition(xml_child);
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in rules section.");
    }
  }
}

ASTNode_Rules::~ASTNode_Rules() {
  for (ASTNode_Rule *rule : rules_) {
    delete rule;
  }
}

void ASTNode_Rules::HandleRuleDefinition(const XMLNode *xml_node) {
  rules_.push_back(new ASTNode_Rule(xml_node));
}

void ASTNode_Rules::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Rules section contains ", rules_.size(), " rules.");
  for (ASTNode_Rule *rule : rules_) {
    rule->PrintDebugInfo(indentation + L"  ");
  }
}
} // namespace xml2cpp
} // namespace apertium
