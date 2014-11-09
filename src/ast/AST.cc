#include "AST.h"

namespace apertium {
namespace xml2cpp {
AST::AST(const XMLTree& xml_tree) {
  const XMLNode *xml_root = xml_tree.get_root();
  root_ = new ASTNode_Root(xml_root);
}

AST::~AST() {
  delete root_;
}
} // namespace apertium
} // namespace xml2cpp
