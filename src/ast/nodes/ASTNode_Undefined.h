#ifndef __APERTIUM_XML2CPP_AST_NODE_UNDEFINED_H
#define __APERTIUM_XML2CPP_AST_NODE_UNDEFINED_H

#include <string>
#include <unordered_map>

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Undefined : public ASTNode {
 public:
  ASTNode_Undefined();
  ~ASTNode_Undefined();
};
} // namespace xml2cpp
} // namespace apertium

#endif
