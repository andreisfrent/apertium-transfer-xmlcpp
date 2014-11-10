#ifndef __APERTIUM_XML2CPP_AST_NODE_GLOBALLISTS_H
#define __APERTIUM_XML2CPP_AST_NODE_GLOBALLISTS_H

#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>
#include <set>

namespace apertium {
namespace xml2cpp {
class ASTNode_GlobalLists : public ASTNode {
 public:
  ASTNode_GlobalLists();
  ASTNode_GlobalLists(const XMLNode *xml_node);
  ~ASTNode_GlobalLists();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  std::unordered_map<std::wstring, std::set<std::wstring>> lists_;

  void HandleListDefinition(const XMLNode *xml_node);
  void HandleListElementDefinition(
      const XMLNode *xml_node, const std::wstring& list_name);
};
} // namespace xml2cpp
} // namespace apertium

#endif
