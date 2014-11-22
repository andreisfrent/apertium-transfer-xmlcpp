#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
B::B(const XMLNode *xml_node)
    : RValue(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"pos"});
  pos_ = xml_node->GetOptionalAttribute(L"pos", L"");

  Error::Assert(
      xml_node->get_children().size() == 0,
      *xml_node, "Element should have no children.");
}
} // namespace xml2cpp
} // namespace apertium
