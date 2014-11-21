#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
VariableBase::VariableBase(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n"});
  name_ = xml_node->GetMandatoryAttribute(L"n");
}
} // namespace xml2cpp
} // namespace apertium
