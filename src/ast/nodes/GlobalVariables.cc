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

void GlobalVariables::HandleVariableDefinition(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n", L"c", L"v"});

  const std::wstring& var_name = xml_node->GetMandatoryAttribute(L"n");
  const std::wstring& initial_value = xml_node->GetOptionalAttribute(L"v", L"");

  if (vars_.find(var_name) != vars_.end()) {
    Error::Warning(*xml_node, "Multiple definitions of global variable \"", var_name, "\".");
  }

  vars_.insert(var_name);
  initial_values_[var_name] = initial_value;
}

void GlobalVariables::PrintDebugInfo(
    const std::wstring& indentation) const {
  Error::Debug(indentation, "Global variables:");
  for (const std::wstring& name : vars_) {
    Error::Debug(indentation, "  ", name);
  }
}

bool GlobalVariables::HasVariable(const std::wstring& name) const {
  return vars_.find(name) != vars_.end();
}

void GlobalVariables::SemanticCheck(const CompilationContext *ctx) const {
}

void GlobalVariables::GenerateCode(CompilationContext *ctx) {
  Error::Debug("GlobalVariables::GenerateCode");

  SymbolTable *symbol_table = ctx->get_symbol_table();

  for (const auto& it : initial_values_) {
    const std::wstring& var_name = it.first;
    const std::wstring& var_value = it.second;
    const std::wstring& symbol_name =
        symbol_table->RegisterSymbol(SymbolType::kVariable, var_name);
    if (var_value.empty()) {
      std::wcout << L"std::wstring " << symbol_name
          << L";" << std::endl;
    } else {
      std::wcout << L"std::wstring " << symbol_name
          << L"(L\"" << var_value << L"\");" << std::endl;
    }
  }
}
} // namespace xml2cpp
} // namespace apertium
