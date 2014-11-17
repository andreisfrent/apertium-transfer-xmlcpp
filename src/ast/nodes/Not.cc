#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Not::Not(const XMLNode *xml_node)
  : Condition(xml_node) {
  const auto& xml_children = xml_node->get_children();
  if (xml_children.size() != 1) {
    Error::Fatal(*xml_node, "Wrong number of children.");
  }
  condition_ = Condition::FromXMLNode(xml_children.at(0));
}

Not::~Not() {
}
} // namespace xml2cpp
} // namespace apertium
