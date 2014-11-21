#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
LValue::LValue(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

LValue::~LValue() {
}

LValue* LValue::FromXMLNode(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"var") {
    return static_cast<LValue*>(new Variable_LValue(xml_node));
  }

  Error::Fatal(*xml_node, "Unrecognized LValue <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
