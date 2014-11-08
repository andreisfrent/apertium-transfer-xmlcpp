#ifndef __APERTIUM_XML2CPP_AST_H
#define __APERTIUM_XML2CPP_AST_H

#include "../parsing/XMLTree.h"
#include "nodes/ASTNode.h"

namespace apertium {
namespace xml2cpp {
class AST {
 public:
  AST();
  ~AST();

  static AST *FromXMLTree(const XMLTree& xml_tree);

 private:
  AST(AST&);
  AST(AST&&);
  AST& operator=(AST&);
  AST& operator=(AST&&);

  ASTNode *root_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
