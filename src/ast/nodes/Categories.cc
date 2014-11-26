#include <apertium_xml2cpp.h>
#include <string>
#include <vector>
#include <sstream>

namespace apertium {
namespace xml2cpp {
CategoryItem::CategoryItem() {
}

CategoryItem::CategoryItem(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"name", L"lemma", L"tags"});
  this->name = xml_node->GetOptionalAttribute(L"name", L"");
  this->lemma = xml_node->GetOptionalAttribute(L"lemma", L"");
  this->tags = xml_node->GetOptionalAttribute(L"tags", L"");
}

Categories::Categories(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"def-cat")) {
    HandleCatDefinition(xml_child);
  }
}

Categories::~Categories() {
}

void Categories::HandleCatDefinition(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n", L"c"});

  const std::wstring& category = xml_node->GetMandatoryAttribute(L"n");

  if (categories_.find(category) != categories_.end()) {
    Error::Fatal(*xml_node, "Multiple definitions of category \"", category, "\".");
  }
  categories_.insert(std::make_pair(category, std::vector<CategoryItem>()));

  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"cat-item")) {
    categories_[category].push_back(CategoryItem(xml_child));
  }
}

void Categories::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Category definitions:");
  Error::Debug(indentation, "NOTE each cat-item is listed as (name, lemma, tags)");
  for (const auto& kv : categories_) {
    std::wstringstream wss;
    wss << kv.first << L" = [";
    size_t item_index = 0;
    for (const CategoryItem& category_item : kv.second) {
      wss << L"(\"" << category_item.name
          << "\", \"" << category_item.lemma
          << "\", \"" << category_item.tags
          << L"\")";
      if (item_index + 1 < kv.second.size()) {
        wss << L", ";
      }
      ++item_index;
    }
    wss << L"]";
    Error::Debug(indentation, "  ", wss.str());
  }
}

void Categories::SemanticCheck(const CompilationContext *ctx) const {
}
} // namespace xml2cpp
} // namespace apertium
