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

void And::SemanticCheck(const CompilationContext *ctx) const {
  for (const ASTNode *child : children_) {
    child->SemanticCheck(ctx);
  }
}
} // namespace xml2cpp
} // namespace apertium
