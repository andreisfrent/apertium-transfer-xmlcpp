#ifndef __APERTIUM_XML2CPP_AST_NODE_INTERCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_INTERCHUNK_H

#include <string>
#include <unordered_map>

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Interchunk : public ASTNode {
 public:
  ASTNode_Interchunk(const XMLNode *xml_node);
  ~ASTNode_Interchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
