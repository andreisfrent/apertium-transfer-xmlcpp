#ifndef __APERTIUM_XML2CPP_AST_NODE_CODEBLOCK_H
#define __APERTIUM_XML2CPP_AST_NODE_CODEBLOCK_H

#include <apertium_xml2cpp.h>

#include <string>
#include <vector>

namespace apertium {
namespace xml2cpp {
class ASTNode_CodeBlock : public ASTNode {
 public:
  ASTNode_CodeBlock(const XMLNode *xml_node);
  ~ASTNode_CodeBlock();

 private:
  std::vector<Statement*> instructions_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
