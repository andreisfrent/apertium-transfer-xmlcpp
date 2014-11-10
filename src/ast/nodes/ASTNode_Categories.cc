#include <apertium_xml2cpp.h>
#include <string>
#include <vector>
#include <sstream>

namespace apertium {
namespace xml2cpp {
CategoryItem::CategoryItem() {
}

CategoryItem::CategoryItem(const XMLNode *xml_node) {
  for (const auto& kv : xml_node->get_attrs()) {
    if (kv.first == L"name") {
      this->name = kv.second;
    } else if (kv.first == L"lemma") {
      this->lemma = kv.second;
    } else if (kv.first == L"tags") {
      this->tags = kv.second;
    } else {
      Error::Fatal("Unknown attribute \"", kv.first, "\" of <cat-item>.");
    }
  }
}

ASTNode_Categories::ASTNode_Categories(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"def-cat") {
      HandleCatDefinition(xml_child);
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in category definition section.");
    }
  }
}

ASTNode_Categories::~ASTNode_Categories() {
}

void ASTNode_Categories::HandleCatDefinition(const XMLNode *xml_node) {
  if (xml_node->get_attrs().find(L"n") == xml_node->get_attrs().end()) {
    Error::Fatal("Category name is missing.");
  }

  const std::wstring& category = xml_node->get_attrs().find(L"n")->second;
  if (categories_.find(category) != categories_.end()) {
    Error::Warning("Multiple definitions of category \"", category, "\".");
  }
  categories_.insert(std::make_pair(category, std::vector<CategoryItem>()));

  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"cat-item") {
      categories_[category].push_back(CategoryItem(xml_child));
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in definition of category \"", category, "\".");
    }
  }
}

void ASTNode_Categories::PrintDebugInfo(const std::wstring& indentation) const {
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
} // namespace xml2cpp
} // namespace apertium
