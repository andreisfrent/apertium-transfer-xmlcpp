#ifndef __APERTIUM_XML2CPP_AST_H
#define __APERTIUM_XML2CPP_AST_H

#include "../parsing/XMLTree.h"
#include "nodes/ASTNode.h"

namespace apertium {
namespace xml2cpp {
class AST {
 public:
  AST(const XMLTree& xml_tree);
  ~AST();

 private:
  AST(AST&);
  AST(AST&&);
  AST& operator=(AST&);
  AST& operator=(AST&&);

  void FreeResources();
  void BuildSubTree(const XMLNode *xml_node, ASTNode *ast_node);

  ASTNode *root_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
