#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Lit::Lit(const XMLNode *xml_node)
    : RValue(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"v"});
  value_ = xml_node->GetMandatoryAttribute(L"v");
  if (xml_node->get_tag() == L"lit") {
    is_tag_ = false;
  } else if (xml_node->get_tag() == L"lit-tag") {
    is_tag_ = true;
  } else {
    Error::Fatal(*xml_node,
        "AST node Lit should only be constructed from lit and lit-tag XML nodes.");
  }
}
} // namespace xml2cpp
} // namespace apertium
