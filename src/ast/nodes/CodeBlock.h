#ifndef __APERTIUM_XML2CPP_AST_NODE_CODEBLOCK_H
#define __APERTIUM_XML2CPP_AST_NODE_CODEBLOCK_H

#include <apertium_xml2cpp.h>

#include <string>
#include <vector>

namespace apertium {
namespace xml2cpp {
class CodeBlock : public ASTNode {
 public:
  CodeBlock(const XMLNode *xml_node);
  CodeBlock(const XMLNode *xml_node,
      const std::vector<XMLNode*>::const_iterator& it_begin,
      const std::vector<XMLNode*>::const_iterator& it_end);
  ~CodeBlock();

 private:
  std::vector<Statement*> instructions_;
  void ctor_init(const XMLNode *xml_node,
      const std::vector<XMLNode*>::const_iterator& it_begin,
      const std::vector<XMLNode*>::const_iterator& it_end);

};
} // namespace xml2cpp
} // namespace apertium

#endif
