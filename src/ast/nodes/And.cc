#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
And::And(const XMLNode *xml_node)
  : Condition(xml_node) {
  xml_node->EmitWarningOnAllAttributes();
  Error::Assert(
      xml_node->get_children().size() >= 2,
      *xml_node, "Not enough children.");

  for (const XMLNode *xml_child : xml_node->get_children()) {
    children_.push_back(Condition::FromXMLNode(xml_child));
  }
}

And::~And() {
  for (Condition *child : children_) {
    delete child;
  }
}

bool And::SemanticCheck(const CompilationContext *ctx) const {
  // Condition nodes always return true, so there is no need to check types.
  // In other words, if we did not fail at AST building time, everything should
  // be fine.
  return true;
}
} // namespace xml2cpp
} // namespace apertium
