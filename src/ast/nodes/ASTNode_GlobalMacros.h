#ifndef __APERTIUM_XML2CPP_AST_NODE_GLOBALMACROS_H
#define __APERTIUM_XML2CPP_AST_NODE_GLOBALMACROS_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_GlobalMacros : public ASTNode {
 public:
  ASTNode_GlobalMacros();
  ASTNode_GlobalMacros(const XMLNode *xml_node);
  ~ASTNode_GlobalMacros();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  std::unordered_map<std::wstring, ASTNode_Macro*> macros_;

  void HandleMacroDefinition(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
