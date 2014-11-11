#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_Rule::ASTNode_Rule(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  code_ = NULL;
  // TODO
}

ASTNode_Rule::~ASTNode_Rule() {
  if (code_) delete code_;
}

void ASTNode_Rule::PrintDebugInfo(const std::wstring& indentation) const {
  // TODO
}
} // namespace xml2cpp
} // namespace apertium
