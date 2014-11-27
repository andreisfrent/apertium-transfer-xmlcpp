#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
GlobalMacros::GlobalMacros() {
}

GlobalMacros::GlobalMacros(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"def-macro")) {
    HandleMacroDefinition(xml_child);
  }
}

GlobalMacros::~GlobalMacros() {
  for (auto& kv : macros_) {
    delete kv.second;
  }
}

void GlobalMacros::HandleMacroDefinition(const XMLNode *xml_node) {
  const std::wstring& macro_name = xml_node->GetMandatoryAttribute(L"n");

  Error::Assert(
      macros_.find(macro_name) == macros_.end(),
      *xml_node, "Multiple definitions of macro \"", macro_name, "\".");

  macros_[macro_name] = new Macro(xml_node);
}

void GlobalMacros::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Macro definitions:");
  for (const auto& kv : macros_) {
    kv.second->PrintDebugInfo(indentation + L"  ");
  }
}

void GlobalMacros::SemanticCheck(const CompilationContext *ctx) const {
  for (const auto& kv : macros_) {
    kv.second->SemanticCheck(ctx);
  }
}

bool GlobalMacros::HasMacro(const std::wstring& name, int param_count) const {
  const auto it = macros_.find(name);
  if (it != macros_.end()) {
    const Macro *macro = it->second;
    if (macro->get_param_count() == param_count) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
} // namespace xml2cpp
} // namespace apertium
