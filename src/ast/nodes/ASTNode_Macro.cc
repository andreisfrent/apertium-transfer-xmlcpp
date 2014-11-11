#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_Macro::ASTNode_Macro(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  HandleXMLAttributes(xml_node);
  code_ = new ASTNode_CodeBlock(xml_node);
}

ASTNode_Macro::~ASTNode_Macro() {
  if (code_) delete code_;
}

void ASTNode_Macro::HandleXMLAttributes(const XMLNode *xml_node) {
  const auto& attrs = xml_node->get_attrs();

  if (attrs.find(L"n") == attrs.end()) {
    Error::Fatal("Macro name is missing.");
  }
  if (attrs.find(L"npar") == attrs.end()) {
    Error::Fatal("Parameter count attribute is mising on <def-macro>.");
  }

  name_ = attrs.find(L"n")->second;
  param_count_ = StringUtil::ConvertTo<int>(attrs.find(L"npar")->second);

  for (const auto& kv : attrs) {
    if (kv.first != L"n" && kv.first != L"npar") {
      Error::Warning("Unknown attribute \"", kv.first, "\" on <def-macro>");
    }
  }
}

void ASTNode_Macro::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Macro ", name_, " of arity ", param_count_, ":");
}
} // namespace xml2cpp
} // namespace apertium
