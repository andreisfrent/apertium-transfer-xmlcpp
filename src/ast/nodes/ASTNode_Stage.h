#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGE_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGE_H

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Stage : public ASTNode {
 public:
  ASTNode_Stage(const XMLNode *xml_node);
  virtual ~ASTNode_Stage();
};
} // namespace xml2cpp
} // namespace apertium

#endif
