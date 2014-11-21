#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
RValue::RValue(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

RValue::~RValue() {
}

RValue* RValue::FromXMLNode(const XMLNode *xml_node) {
  Error::Fatal(*xml_node, "Unrecognized RValue <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
