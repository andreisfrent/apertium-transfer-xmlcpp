#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_Instruction::ASTNode_Instruction(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

ASTNode_Instruction::~ASTNode_Instruction() {
}

ASTNode_Instruction* ASTNode_Instruction::FromXMLNode(const XMLNode *xml_node) {
  Error::Fatal(*xml_node, "Unrecognized instruction <", xml_node->get_tag(), ">.");

  // Avoid getting warnings from the compiler for not returning in a non-void
  // function.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
