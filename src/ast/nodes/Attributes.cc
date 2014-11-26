#include <apertium_xml2cpp.h>
#include <string>
#include <set>
#include <sstream>

namespace apertium {
namespace xml2cpp {
Attributes::Attributes(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"def-attr")) {
    HandleAttrDefinition(xml_child);
  }
}

Attributes::~Attributes() {
}

void Attributes::HandleAttrDefinition(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n", L"c"});
  const std::wstring& attribute = xml_node->GetMandatoryAttribute(L"n");
  if (attributes_.find(attribute) != attributes_.end()) {
    Error::Fatal(*xml_node, "Multiple definitions of attribute \"", attribute, "\".");
  }
  attributes_.insert(std::make_pair(attribute, std::set<std::wstring>()));

  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"attr-item")) {
    HandleAttrItemDefinition(xml_child, attribute);
  }
}

void Attributes::HandleAttrItemDefinition(
    const XMLNode *xml_node, const std::wstring& attribute) {
  const std::wstring& attribute_item = xml_node->GetMandatoryAttribute(L"tags");
  attributes_[attribute].insert(attribute_item);
}

void Attributes::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Attributes:");
  for (const auto& kv : attributes_) {
    std::wstringstream wss;
    wss << kv.first << L" = [";
    size_t item_index = 0;
    for (const std::wstring& attribute_item : kv.second) {
      wss << attribute_item;
      if (item_index + 1 < kv.second.size()) {
        wss << L", ";
      }
      ++item_index;
    }
    wss << L"]";
    Error::Debug(indentation, "  ", wss.str());
  }
}

void Attributes::SemanticCheck(const CompilationContext *ctx) const {
}
} // namespace xml2cpp
} // namespace apertium
