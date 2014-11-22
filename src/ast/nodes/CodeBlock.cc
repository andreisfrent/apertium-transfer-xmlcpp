#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
CodeBlock::CodeBlock(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  ctor_init(xml_node,
      xml_node->get_children().begin(),
      xml_node->get_children().end());
}

CodeBlock::CodeBlock(const XMLNode *xml_node,
    const std::vector<XMLNode*>::const_iterator& it_begin,
    const std::vector<XMLNode*>::const_iterator& it_end)
    : ASTNode(xml_node) {
  ctor_init(xml_node, it_begin, it_end);
}

CodeBlock::~CodeBlock() {
  for (const Statement *instruction : instructions_) {
    delete instruction;
  }
}

void CodeBlock::ctor_init(const XMLNode *xml_node,
    const std::vector<XMLNode*>::const_iterator& it_begin,
    const std::vector<XMLNode*>::const_iterator& it_end) {
  for (auto it = it_begin; it != it_end; ++it) {
    Statement *statement = Statement::FromXMLNode(*it);
    instructions_.push_back(statement);
  }
}
} // namespace xml2cpp
} // namespace apertium
