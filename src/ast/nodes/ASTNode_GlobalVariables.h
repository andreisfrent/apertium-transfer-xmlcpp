#ifndef __APERTIUM_XML2CPP_AST_NODE_GLOBALVARIABLES_H
#define __APERTIUM_XML2CPP_AST_NODE_GLOBALVARIABLES_H

#include <apertium_xml2cpp.h>
#include <string>
#include <set>

namespace apertium {
namespace xml2cpp {
class ASTNode_GlobalVariables : public ASTNode {
 public:
  ASTNode_GlobalVariables();
  ASTNode_GlobalVariables(const XMLNode *xml_node);
  ~ASTNode_GlobalVariables();

  void PrintVariableNames();

 private:
  std::set<std::wstring> var_names_;

  void HandleVariableDefinition(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
