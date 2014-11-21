#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
const int SubstrCmp::kBegin = 0;
const int SubstrCmp::kEnd = 1;
const int SubstrCmp::kAnywhere = 2;

SubstrCmp::SubstrCmp(const XMLNode *xml_node)
  : Condition(xml_node) {
  HandleXMLTag(xml_node);
  HandleXMLAttributes(xml_node);
  HandleXMLChildren(xml_node);
}

SubstrCmp::~SubstrCmp() {
  delete op1_;
  delete op2_;
}

void SubstrCmp::HandleXMLTag(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"begins-with") {
    where_ = kBegin;
  } else if (xml_node->get_tag() == L"ends-with") {
    where_ = kEnd;
  } else if (xml_node->get_tag() == L"contains-substring") {
    where_ = kAnywhere;
  } else {
    Error::Fatal("No suitable tag value for SubstrCmp object.");
  }
}

void SubstrCmp::HandleXMLChildren(const XMLNode *xml_node) {
  const auto& children = xml_node->get_children();
  if (children.size() != 2) {
    Error::Fatal(*xml_node, "Wrong number of operands.");
  }

  op1_ = LValue::FromXMLNode(children.at(0));
  op2_ = LValue::FromXMLNode(children.at(1));
}

void SubstrCmp::HandleXMLAttributes(const XMLNode *xml_node) {
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
