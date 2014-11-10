#include <apertium_xml2cpp.h>
#include <string>
#include <set>

namespace apertium {
namespace xml2cpp {
ASTNode_GlobalVariables::ASTNode_GlobalVariables(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"def-var") {
      HandleVariableDefinition(xml_child);
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in global variables section.");
    }
  }
}

ASTNode_GlobalVariables::ASTNode_GlobalVariables()
    : ASTNode() {
}

ASTNode_GlobalVariables::~ASTNode_GlobalVariables() {
}

void ASTNode_GlobalVariables::HandleVariableDefinition(const XMLNode *xml_node) {
  if (xml_node->get_children().size() != 0) {
    Error::Fatal("Encountered <def-var> tag with children.");
  }

  if (xml_node->get_attrs().find(L"n") == xml_node->get_attrs().end()) {
    Error::Fatal("Global variable name is missing.");
  }

  const std::wstring& var_name = xml_node->get_attrs().find(L"n")->second;
  if (IsValidVariableName(var_name)) {
    var_names_.insert(var_name);
  } else {
    Error::Fatal("Variable name \"", var_name, "\" is not valid.");
  }
}

bool ASTNode_GlobalVariables::IsValidVariableName(const std::wstring& var_name) {
  Error::Unimplemented("ASTNode_GlobalVariables::IsValidVariableName");
  return true;
}

void ASTNode_GlobalVariables::PrintVariableNames() {
  Error::Debug("Global variables:");
  for (const std::wstring& name : var_names_) {
    Error::Debug("  ", name);
  }
}
} // namespace xml2cpp
} // namespace apertium
