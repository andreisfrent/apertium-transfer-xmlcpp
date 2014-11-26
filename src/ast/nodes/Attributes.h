#ifndef __APERTIUM_XML2CPP_ATTRIBUTES_H
#define __APERTIUM_XML2CPP_ATTRIBUTES_H

#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>
#include <set>

namespace apertium {
namespace xml2cpp {
class Attributes : public ASTNode {
 public:
  Attributes(const XMLNode *xml_node);
  ~Attributes();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;
  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::unordered_map<std::wstring, std::set<std::wstring>> attributes_;

  void HandleAttrDefinition(const XMLNode *xml_node);
  void HandleAttrItemDefinition(
      const XMLNode *xml_node, const std::wstring& list_name);
};
} // namespace xml2cpp
} // namespace apertium

#endif
