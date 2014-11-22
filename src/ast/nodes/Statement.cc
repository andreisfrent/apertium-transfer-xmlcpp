#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Statement::Statement(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

Statement::~Statement() {
}

Statement* Statement::FromXMLNode(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"call-macro") {
    return new CallMacro(xml_node);
  } else if (xml_node->get_tag() == L"choose") {
    return new Choose(xml_node);
  }

  Error::Fatal(*xml_node, "Unrecognized instruction <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
