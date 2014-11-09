#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGETRANSFER_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGETRANSFER_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_StageTransfer : public ASTNode_Stage {
 public:
  ASTNode_StageTransfer(const XMLNode *xml_node);
  ~ASTNode_StageTransfer();
};
} // namespace xml2cpp
} // namespace apertium

#endif
