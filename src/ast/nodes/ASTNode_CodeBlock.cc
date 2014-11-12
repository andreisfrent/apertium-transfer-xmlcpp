#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_CodeBlock::ASTNode_CodeBlock(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    ASTNode_Instruction *instruction = ASTNode_Instruction::FromXMLNode(xml_child);
    instructions_.push_back(instruction);
  }
}

ASTNode_CodeBlock::~ASTNode_CodeBlock() {
  for (const ASTNode_Instruction *instruction : instructions_) {
    delete instruction;
  }
}
} // namespace xml2cpp
} // namespace apertium
