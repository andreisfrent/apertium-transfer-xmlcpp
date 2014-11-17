#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
AST::AST(const XMLTree& xml_tree) {
  const XMLNode *xml_root = xml_tree.get_root();
  root_ = new Root(xml_root);
}

AST::~AST() {
  delete root_;
}

void AST::PrintDebugInfo() const {
  root_->PrintDebugInfo();
}
} // namespace apertium
} // namespace xml2cpp
