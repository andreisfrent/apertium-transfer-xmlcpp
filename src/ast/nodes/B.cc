#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
B::B(const XMLNode *xml_node)
    : RValue(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"pos"});
  pos_ = xml_node->GetMandatoryAttribute(L"pos");
}
} // namespace xml2cpp
} // namespace apertium
