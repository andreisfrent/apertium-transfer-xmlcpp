#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Clip_LValue::Clip_LValue(const XMLNode *xml_node)
    : LValue(xml_node), ClipBase(xml_node) {
}

void Clip_LValue::SemanticCheck(const CompilationContext *ctx) const {
  // TODO should check part is in attributes (or something).
}
} // namespace xml2cpp
} // namespace apertium
