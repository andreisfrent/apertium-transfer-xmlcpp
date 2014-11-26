#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Variable_LValue::Variable_LValue(const XMLNode *xml_node)
    : LValue(xml_node), VariableBase(xml_node) {
}

void Variable_LValue::SemanticCheck(const CompilationContext *ctx) const {
  ctx->AssertVariable(this, name_);
}
} // namespace xml2cpp
} // namespace apertium
