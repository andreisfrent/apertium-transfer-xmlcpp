#include "AST.h"

#include "nodes/ASTNode.h"

#include <iostream>
#include <stdexcept>

namespace apertium {
namespace xml2cpp {
AST::AST(const XMLTree& xml_tree) {
  const XMLNode *xml_root = xml_tree.get_root();
  root_ = ASTNode::FromXMLNode(*xml_root);
  if (root_ == NULL) {
    throw std::runtime_error("Error! AST building failed on root node.");
  }

  try {
    BuildSubTree(xml_root, root_);
  } catch (std::exception& ex) {
    FreeResources();
    throw ex;
  }
}

void AST::FreeResources() {
  delete root_;
}

void AST::BuildSubTree(const XMLNode *xml_node, ASTNode *ast_node) {
  for(const XMLNode *xml_child : xml_node->get_children()) {
    ASTNode *ast_child = ASTNode::FromXMLNode(*xml_child);
    if (ast_child == NULL) {
      // TODO Better description.
      throw std::runtime_error("Error! AST building failed on an internal node.");
    }
    ast_node->AddChild(ast_child);
    BuildSubTree(xml_child, ast_child);
  }
}

AST::~AST() {
  FreeResources();
}
} // namespace xml2cpp
} // namespace apertium
