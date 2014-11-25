#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Macro::Macro(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  HandleXMLAttributes(xml_node);
  code_ = new CodeBlock(xml_node);
}

Macro::~Macro() {
  delete code_;
}

void Macro::HandleXMLAttributes(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n", L"npar", L"c"});
  name_ = xml_node->GetMandatoryAttribute(L"n");
  param_count_ = xml_node->GetMandatoryAttributeAs<int>(L"npar");
}

void Macro::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Macro ", name_, " of arity ", param_count_, ":");
}

void Macro::SemanticCheck(const CompilationContext *ctx) const {
  code_->SemanticCheck(ctx);
}
} // namespace xml2cpp
} // namespace apertium
