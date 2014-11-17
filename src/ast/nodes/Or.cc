#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Or::Or(const XMLNode *xml_node)
  : Condition(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    children_.push_back(Condition::FromXMLNode(xml_child));
  }
  if (children_.size() <= 1) {
    Error::Fatal(*xml_node, "Not enough children.");
  }
}

Or::~Or() {
}
} // namespace xml2cpp
} // namespace apertium
