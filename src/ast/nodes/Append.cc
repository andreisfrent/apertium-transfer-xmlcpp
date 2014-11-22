#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Append::Append(const XMLNode *xml_node)
    : Statement(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n"});
  var_name_ = xml_node->GetMandatoryAttribute(L"n");

  for (const XMLNode *xml_child : xml_node->get_children()) {
    values_.push_back(RValue::FromXMLNode(xml_child));
  }
}

Append::~Append() {
  for (RValue *rvalue : values_) {
    delete rvalue;
  }
  values_.clear();
}

} // namespace xml2cpp
} // namespace apertium
