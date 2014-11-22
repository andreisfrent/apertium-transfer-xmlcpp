#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
RValue::RValue(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

RValue::~RValue() {
}

RValue* RValue::FromXMLNode(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"var") {
    return static_cast<RValue*>(new Variable_RValue(xml_node));
  } else if (xml_node->get_tag() == L"clip") {
    return static_cast<RValue*>(new Clip_RValue(xml_node));
  } else if (xml_node->get_tag() == L"lit" ||
             xml_node->get_tag() == L"lit-tag") {
    return static_cast<RValue*>(new Lit(xml_node));
  } else if (xml_node->get_tag() == L"b") {
    return static_cast<RValue*>(new B(xml_node));
  } else if (xml_node->get_tag() == L"lu") {
    return static_cast<RValue*>(new Lu(xml_node));
  } else if (xml_node->get_tag() == L"mlu") {
    return static_cast<RValue*>(new Mlu(xml_node));
  } else if (xml_node->get_tag() == L"chunk") {
    return static_cast<RValue*>(new Chunk(xml_node));
  } else if (xml_node->get_tag() == L"concat") {
    return static_cast<RValue*>(new Concat(xml_node));
  }

  Error::Fatal(*xml_node, "Unrecognized RValue <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
