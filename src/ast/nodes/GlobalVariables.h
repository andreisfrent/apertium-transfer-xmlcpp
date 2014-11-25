#ifndef __APERTIUM_XML2CPP_GLOBALVARIABLES_H
#define __APERTIUM_XML2CPP_GLOBALVARIABLES_H

#include <apertium_xml2cpp.h>
#include <string>
#include <set>

namespace apertium {
namespace xml2cpp {
class GlobalVariables : public ASTNode {
 public:
  GlobalVariables();
  GlobalVariables(const XMLNode *xml_node);

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;
  bool HasVariable(const std::wstring& name) const;
  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::set<std::wstring> vars_;
  std::unordered_map<std::wstring, std::wstring> initial_values_;

  void HandleVariableDefinition(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
