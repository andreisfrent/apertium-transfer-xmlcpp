#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Out::Out(const XMLNode *xml_node)
    : Statement(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"c"});

  Error::Assert(
      xml_node->get_children().size() >= 1,
      *xml_node, "No children.");

  for (const XMLNode *xml_child : xml_node->get_children()) {
    values_.push_back(RValue::FromXMLNode(xml_child));
  }
}

Out::~Out() {
  for (RValue *rvalue : values_) {
    delete rvalue;
  }
  values_.clear();
}

void Out::SemanticCheck(const CompilationContext *ctx) const {
  for (const RValue *rvalue : values_) {
    rvalue->SemanticCheck(ctx);
  }
}
} // namespace xml2cpp
} // namespace apertium
