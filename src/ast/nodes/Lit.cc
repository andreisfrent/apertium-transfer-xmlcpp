#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Lit::Lit(const XMLNode *xml_node)
    : RValue(xml_node) {
  Error::Assert(
      xml_node->get_tag() == L"lit" || xml_node->get_tag() == L"lit-tag",
      *xml_node, "AST node Lit should only be constructed from lit and lit-tag XML nodes.");

  xml_node->EmitWarningOnUnknownAttributes({L"v"});
  value_ = xml_node->GetMandatoryAttribute(L"v");

  if (xml_node->get_tag() == L"lit-tag") {
    value_ = L"<" + value_ + L">";
  }
}

void Lit::SemanticCheck(const CompilationContext *ctx) const {
}
} // namespace xml2cpp
} // namespace apertium
