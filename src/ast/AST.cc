#include "AST.h"

#include "nodes/ASTNode.h"

namespace apertium {
namespace xml2cpp {

namespace {
ASTNode *BuildSubTree(const XMLNode& xml_node) {
  ASTNode *ast_node = ASTNode::FromXMLNode(xml_node);
  for (const XMLNode *xml_child : xml_node.get_children()) {
    ASTNode *ast_child = BuildSubTree(*xml_child);
    ast_node->AddChild(ast_child);
  }
  return ast_node;
}
}

AST::AST(ASTNode *root) {
  root_ = root;
}

AST::~AST() {
  delete root_;
}

AST *AST::FromXMLTree(const XMLTree& xml_tree) {
  const XMLNode *xml_root = xml_tree.get_root();
  ASTNode *ast_root = BuildSubTree(*xml_root);
  return new AST(ast_root);
}

} // namespace xml2cpp
} // namespace apertium
