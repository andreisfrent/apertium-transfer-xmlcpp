#ifndef __APERTIUM_XML2CPP_AST_NODE_POSTCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_POSTCHUNK_H

#include <string>
#include <unordered_map>

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Postchunk : public ASTNode {
 public:
  ASTNode_Postchunk(const XMLNode *xml_node);
  ~ASTNode_Postchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
