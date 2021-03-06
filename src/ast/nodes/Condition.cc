#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Condition::Condition(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

Condition* Condition::FromXMLNode(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"and") {
    return new And(xml_node);
  } else if (xml_node->get_tag() == L"or") {
    return new Or(xml_node);
  } else if (xml_node->get_tag() == L"not") {
    return new Not(xml_node);
  } else if (xml_node->get_tag() == L"equal") {
    return new Equal(xml_node);
  } else if (xml_node->get_tag() == L"begins-with" ||
             xml_node->get_tag() == L"ends-with" ||
             xml_node->get_tag() == L"contains-substring") {
    return new SubstrCmp(xml_node);
  } else if (xml_node->get_tag() == L"begins-with-list" ||
             xml_node->get_tag() == L"ends-with-list" ||
             xml_node->get_tag() == L"in") {
    return new SubstrCmpList(xml_node);
  }

  Error::Fatal(*xml_node, "Unrecognized instruction <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
