#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_GlobalMacros::ASTNode_GlobalMacros() {
}

ASTNode_GlobalMacros::ASTNode_GlobalMacros(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"def-macro") {
      HandleMacroDefinition(xml_child);
    } else {
      Error::Fatal(*xml_child, "Unexpected <", xml_child->get_tag(), "> in macros definition section.");
    }
  }
}

ASTNode_GlobalMacros::~ASTNode_GlobalMacros() {
  for (auto& kv : macros_) {
    delete kv.second;
  }
}

void ASTNode_GlobalMacros::HandleMacroDefinition(const XMLNode *xml_node) {
  if (xml_node->get_attrs().find(L"n") == xml_node->get_attrs().end()) {
    Error::Fatal(*xml_node, "Macro name is missing.");
  }

  const std::wstring& macro_name = xml_node->get_attrs().find(L"n")->second;
  if (macros_.find(macro_name) != macros_.end()) {
    Error::Warning(*xml_node, "Multiple definitions of macro \"", macro_name, "\".");
  }

  macros_[macro_name] = new ASTNode_Macro(xml_node);
}

void ASTNode_GlobalMacros::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Macro definitions:");
  for (const auto& kv : macros_) {
    kv.second->PrintDebugInfo(indentation + L"  ");
  }
}
} // namespace xml2cpp
} // namespace apertium
