#ifndef __APERTIUM_XML2CPP_NEW_AST_H
#define __APERTIUM_XML2CPP_NEW_AST_H

#include "../parsing/XMLTree.h"
#include "nodes/ASTNode_Root.h"

namespace apertium {
namespace xml2cpp {
class AST {
 public:
  AST(const XMLTree& xml_tree);
  ~AST();

 private:
  ASTNode_Root *root_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
