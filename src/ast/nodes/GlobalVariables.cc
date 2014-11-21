#include <apertium_xml2cpp.h>
#include <string>
#include <set>

namespace apertium {
namespace xml2cpp {
GlobalVariables::GlobalVariables(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"def-var")) {
    HandleVariableDefinition(xml_child);
  }
}

GlobalVariables::GlobalVariables()
    : ASTNode() {
}

GlobalVariables::~GlobalVariables() {
}

void GlobalVariables::HandleVariableDefinition(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n", L"c"});
  const std::wstring& var_name = xml_node->GetMandatoryAttribute(L"n");
  if (var_names_.find(var_name) != var_names_.end()) {
    Error::Warning(*xml_node, "Multiple definitions of global variable \"", var_name, "\".");
  }
  var_names_.insert(var_name);
}

void GlobalVariables::PrintDebugInfo(
    const std::wstring& indentation) const {
  Error::Debug(indentation, "Global variables:");
  for (const std::wstring& name : var_names_) {
    Error::Debug(indentation, "  ", name);
  }
}
} // namespace xml2cpp
} // namespace apertium
