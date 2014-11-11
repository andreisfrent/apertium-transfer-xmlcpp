#ifndef __APERTIUM_XML2CPP_AST_NODE_MACRO_H
#define __APERTIUM_XML2CPP_AST_NODE_MACRO_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_Macro : public ASTNode {
 public:
  ASTNode_Macro(const XMLNode *xml_node);
  ~ASTNode_Macro();

  void HandleXMLAttributes(const XMLNode *xml_node);

 private:
  std::wstring name_;
  int param_count_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
