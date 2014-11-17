#ifndef __APERTIUM_XML2CPP_AST_NODE_MACRO_H
#define __APERTIUM_XML2CPP_AST_NODE_MACRO_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Macro : public ASTNode {
 public:
  Macro(const XMLNode *xml_node);
  ~Macro();

  void HandleXMLAttributes(const XMLNode *xml_node);
  void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  std::wstring name_;
  int param_count_;
  CodeBlock *code_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
