#ifndef __APERTIUM_XML2CPP_GLOBALMACROS_H
#define __APERTIUM_XML2CPP_GLOBALMACROS_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class GlobalMacros : public ASTNode {
 public:
  GlobalMacros();
  GlobalMacros(const XMLNode *xml_node);
  ~GlobalMacros();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;
  void SemanticCheck(const CompilationContext *ctx) const override;
  bool HasMacro(const std::wstring& name, int param_count) const;

 private:
  std::unordered_map<std::wstring, Macro*> macros_;

  void HandleMacroDefinition(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
