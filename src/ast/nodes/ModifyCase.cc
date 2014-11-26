#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ModifyCase::ModifyCase(const XMLNode *xml_node)
    : Statement(xml_node) {
  Error::Assert(
      xml_node->get_children().size() == 2,
      *xml_node, "Node should have exactly 2 children.");
  left_ = LValue::FromXMLNode(xml_node->get_children().at(0));
  right_ = RValue::FromXMLNode(xml_node->get_children().at(1));
}

ModifyCase::~ModifyCase() {
  delete left_;
  delete right_;
}

void ModifyCase::SemanticCheck(const CompilationContext *ctx) const {
  left_->SemanticCheck(ctx);
  right_->SemanticCheck(ctx);
}
} // namespace xml2cpp
} // namespace apertium
