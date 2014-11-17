#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Condition::Condition(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

Condition::~Condition() {
}

Condition* Condition::FromXMLNode(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"and") {
    return new And(xml_node);
  }

  Error::Fatal(*xml_node, "Unrecognized instruction <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
