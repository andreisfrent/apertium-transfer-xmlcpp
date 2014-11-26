#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Mlu::Mlu(const XMLNode *xml_node)
    : RValue(xml_node) {
  // TODO ensure no attributes.

  Error::Assert(
      xml_node->get_children().size() >= 1,
      *xml_node, "Element should have at least one child.");

  for (const XMLNode *xml_child : xml_node->get_children()) {
    values_.push_back(new Lu(xml_child));
  }
}

Mlu::~Mlu() {
  for (Lu *lu : values_) {
    delete lu;
  }
}

void Mlu::SemanticCheck(const CompilationContext *ctx) const {
  for (const Lu *lu : values_) {
    lu->SemanticCheck(ctx);
  }
}
} // namespace xml2cpp
} // namespace apertium
