#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
RValue::RValue(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

RValue* RValue::FromXMLNode(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"var") {
    return new Variable_RValue(xml_node);
  } else if (xml_node->get_tag() == L"clip") {
    return new Clip_RValue(xml_node);
  } else if (xml_node->get_tag() == L"lit" ||
             xml_node->get_tag() == L"lit-tag") {
    return new Lit(xml_node);
  } else if (xml_node->get_tag() == L"b") {
    return new B(xml_node);
  } else if (xml_node->get_tag() == L"lu") {
    return new Lu(xml_node);
  } else if (xml_node->get_tag() == L"mlu") {
    return new Mlu(xml_node);
  } else if (xml_node->get_tag() == L"chunk") {
    return new Chunk(xml_node);
  } else if (xml_node->get_tag() == L"concat") {
    return new Concat(xml_node);
  } else if (xml_node->get_tag() == L"case-of") {
    return new CaseOf(xml_node);
  } else if (xml_node->get_tag() == L"get-case-from") {
    return new GetCaseFrom(xml_node);
  }

  Error::Fatal(*xml_node, "Unrecognized RValue <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
