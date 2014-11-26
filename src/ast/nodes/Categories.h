#ifndef __APERTIUM_XML2CPP_AST_NODE_CATEGORIES_H
#define __APERTIUM_XML2CPP_AST_NODE_CATEGORIES_H

#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>
#include <set>

namespace apertium {
namespace xml2cpp {
// TODO Consider converting to a proper class.
struct CategoryItem {
  CategoryItem();
  CategoryItem(const XMLNode *xml_node);

  // Data members.
  std::wstring name;
  std::wstring lemma;
  std::wstring tags;
};

class Categories : public ASTNode {
 public:
  Categories(const XMLNode *xml_node);
  ~Categories();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;
  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::unordered_map<std::wstring, std::vector<CategoryItem>> categories_;

  void HandleCatDefinition(const XMLNode *xml_node);
  void HandleCatItemDefinition(
      const XMLNode *xml_node, const std::wstring& category);
};
} // namespace xml2cpp
} // namespace apertium

#endif
