#ifndef __APERTIUM_XML2CPP_GLOBALLISTS_H
#define __APERTIUM_XML2CPP_GLOBALLISTS_H

#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>
#include <set>

namespace apertium {
namespace xml2cpp {
class GlobalLists : public ASTNode {
 public:
  GlobalLists();
  GlobalLists(const XMLNode *xml_node);

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;
  void SemanticCheck(const CompilationContext *ctx) const override;
  bool HasList(const std::wstring& name_) const;

 private:
  std::unordered_map<std::wstring, std::set<std::wstring>> lists_;

  void HandleListDefinition(const XMLNode *xml_node);
  void HandleListElementDefinition(
      const XMLNode *xml_node, const std::wstring& list_name);
};
} // namespace xml2cpp
} // namespace apertium

#endif
