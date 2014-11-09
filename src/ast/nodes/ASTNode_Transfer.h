#ifndef __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H
#define __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_Transfer : public ASTNode_Stage {
 public:
  ASTNode_Transfer(const XMLNode *xml_node);
  ~ASTNode_Transfer();
};
} // namespace xml2cpp
} // namespace apertium

#endif
