#ifndef __APERTIUM_XML2CPP_AST_NODE_ROOT_H
#define __APERTIUM_XML2CPP_AST_NODE_ROOT_H

#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
class ASTNode_Root : public ASTNode {
 public:
  ASTNode_Root(const XMLNode *xml_node);
  ~ASTNode_Root();

 private:
  ASTNode_Stage *stage_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
