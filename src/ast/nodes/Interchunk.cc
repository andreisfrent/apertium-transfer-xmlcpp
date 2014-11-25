#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Interchunk::Interchunk(const XMLNode *xml_node)
    : Stage(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"c"});
}

void Interchunk::SemanticCheck(const CompilationContext *ctx) const {
  Stage::SemanticCheck(ctx);
}
} // namespace xml2cpp
} // namespace apertium
