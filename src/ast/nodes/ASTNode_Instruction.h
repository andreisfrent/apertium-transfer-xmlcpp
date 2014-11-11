#ifndef __APERTIUM_XML2CPP_AST_NODE_INSTRUCTION_H
#define __APERTIUM_XML2CPP_AST_NODE_INSTRUCTION_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_Instruction : public ASTNode {
 public:
  ASTNode_Instruction(const XMLNode *xml_node);
  ~ASTNode_Instruction();
};
} // namespace xml2cpp
} // namespace apertium

#endif
