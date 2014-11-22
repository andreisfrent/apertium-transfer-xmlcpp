#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Equal::Equal(const XMLNode *xml_node)
  : Condition(xml_node) {
  HandleXMLAttributes(xml_node);
  HandleXMLChildren(xml_node);
}

Equal::~Equal() {
  delete op1_;
  delete op2_;
}

void Equal::HandleXMLChildren(const XMLNode *xml_node) {
  const auto& children = xml_node->get_children();
  if (children.size() != 2) {
    Error::Fatal(*xml_node, "Wrong number of operands.");
  }

  op1_ = RValue::FromXMLNode(children.at(0));
  op2_ = RValue::FromXMLNode(children.at(1));
}

void Equal::HandleXMLAttributes(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"caseless"});

  std::wstring str_caseless = xml_node->GetOptionalAttribute(L"caseless", L"no");
  if (str_caseless == L"yes") {
    caseless_ = true;
  } else if (str_caseless == L"no") {
    caseless_ = false;
  } else {
    Error::Fatal(*xml_node, "Invalid caseless value.");
  }
}
} // namespace xml2cpp
} // namespace apertium
