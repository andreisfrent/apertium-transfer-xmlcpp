#include <apertium_xml2cpp.h>
#include <string>
#include <vector>

namespace apertium {
namespace xml2cpp {
Rules::Rules(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"rule") {
      HandleRuleDefinition(xml_child);
    } else {
      Error::Fatal(*xml_child, "Unexpected <", xml_child->get_tag(), "> in rules section.");
    }
  }
}

Rules::~Rules() {
  for (Rule *rule : rules_) {
    delete rule;
  }
}

void Rules::HandleRuleDefinition(const XMLNode *xml_node) {
  rules_.push_back(new Rule(xml_node));
}

void Rules::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Rules section contains ", rules_.size(), " rules.");
  for (Rule *rule : rules_) {
    rule->PrintDebugInfo(indentation + L"  ");
  }
}
} // namespace xml2cpp
} // namespace apertium
