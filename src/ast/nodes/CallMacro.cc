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
  const auto& attrs = xml_node->get_attrs();
  if (attrs.find(L"n") == attrs.end()) {
    Error::Fatal(*xml_node, "Which macro to call?");
  }
  macro_ = attrs.find(L"n")->second;
}

void CallMacro::ExtractArgumentsFromXMLNode(const XMLNode *xml_node) {
  const std::vector<XMLNode*> arg_vector = xml_node->GetChildrenByTag(L"with-param");
  for (const XMLNode *arg_node : arg_vector) {
    HandleArgumentNode(arg_node);
  }
}

void CallMacro::HandleArgumentNode(const XMLNode *xml_node) {
  const auto& attrs = xml_node->get_attrs();
  if (attrs.find(L"pos") == attrs.end()) {
    Error::Fatal(*xml_node, "Bad parameter format (\"pos\" attribute not found).");
  }

  args_.push_back(StringUtil::ConvertTo<int>(attrs.find(L"pos")->second));
}
} // namespace xml2cpp
} // namespace apertium
