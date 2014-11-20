#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
CallMacro::CallMacro(const XMLNode *xml_node)
    : Statement(xml_node) {
  HandleXMLAttributes(xml_node);
  ExtractArgumentsFromXMLNode(xml_node);
}

CallMacro::~CallMacro() {
}

void CallMacro::HandleXMLAttributes(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n", L"c"});
  macro_ = xml_node->GetMandatoryAttribute(L"n");
}

void CallMacro::ExtractArgumentsFromXMLNode(const XMLNode *xml_node) {
  const std::vector<XMLNode*> arg_vector = xml_node->GetChildrenByTag(L"with-param");
  for (const XMLNode *arg_node : arg_vector) {
    args_.push_back(arg_node->GetMandatoryAttributeAs<int>(L"pos"));
  }
}

} // namespace xml2cpp
} // namespace apertium
