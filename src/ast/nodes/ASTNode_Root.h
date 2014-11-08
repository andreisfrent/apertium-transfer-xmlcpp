#ifndef __APERTIUM_XML2CPP_AST_NODE_ROOT_H
#define __APERTIUM_XML2CPP_AST_NODE_ROOT_H

#include <string>
#include <unordered_map>

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Root : public ASTNode {
 public:
  ASTNode_Root();
  ~ASTNode_Root();
};
} // namespace xml2cpp
} // namespace apertium

#endif
