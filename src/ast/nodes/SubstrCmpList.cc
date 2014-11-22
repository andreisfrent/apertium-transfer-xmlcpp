#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
const int SubstrCmpList::kBegin = 0;
const int SubstrCmpList::kEnd = 1;
const int SubstrCmpList::kExact = 2;

SubstrCmpList::SubstrCmpList(const XMLNode *xml_node)
  : Condition(xml_node) {
  HandleXMLTag(xml_node);
  HandleXMLAttributes(xml_node);
  HandleXMLChildren(xml_node);
}

SubstrCmpList::~SubstrCmpList() {
  delete substr_;
}

void SubstrCmpList::HandleXMLTag(const XMLNode *xml_node) {
  if (xml_node->get_tag() == L"begins-with-list") {
    where_ = kBegin;
  } else if (xml_node->get_tag() == L"ends-with-list") {
    where_ = kEnd;
  } else if (xml_node->get_tag() == L"in") {
    where_ = kExact;
  } else {
    Error::Fatal("No suitable tag value for SubstrCmpList object.");
  }
}

void SubstrCmpList::HandleXMLChildren(const XMLNode *xml_node) {
  const auto& children = xml_node->get_children();
  if (children.size() != 2) {
    Error::Fatal(*xml_node, "Wrong number of operands.");
  }

  substr_ = RValue::FromXMLNode(children.at(0));
  HandleListReference(children.at(1));
}

void SubstrCmpList::HandleListReference(const XMLNode *xml_node) {
  Error::Assert(
      xml_node->get_tag() == L"list",
      *xml_node, "Second operand of <", this->get_tag(), "> should be <list>.");
  xml_node->EmitWarningOnUnknownAttributes({L"n"});
  list_ = xml_node->GetMandatoryAttribute(L"n");
}

void SubstrCmpList::HandleXMLAttributes(const XMLNode *xml_node) {
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
