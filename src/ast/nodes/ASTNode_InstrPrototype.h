#ifndef __APERTIUM_XML2CPP_AST_NODE_INSTRPROTOTYPE_H
#define __APERTIUM_XML2CPP_AST_NODE_INSTRPROTOTYPE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_InstrPrototype : public ASTNode_Instruction {
 public:
  ASTNode_InstrPrototype(const XMLNode *xml_node);
  ~ASTNode_InstrPrototype();
};
} // namespace xml2cpp
} // namespace apertium

#endif
