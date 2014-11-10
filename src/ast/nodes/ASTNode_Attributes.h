#ifndef __APERTIUM_XML2CPP_AST_NODE_ATTRIBUTES_H
#define __APERTIUM_XML2CPP_AST_NODE_ATTRIBUTES_H

#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>
#include <set>

namespace apertium {
namespace xml2cpp {
class ASTNode_Attributes : public ASTNode {
 public:
  ASTNode_Attributes(const XMLNode *xml_node);
  ~ASTNode_Attributes();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  std::unordered_map<std::wstring, std::set<std::wstring>> attributes_;

  void HandleAttrDefinition(const XMLNode *xml_node);
  void HandleAttrItemDefinition(
      const XMLNode *xml_node, const std::wstring& list_name);
};
} // namespace xml2cpp
} // namespace apertium

#endif
