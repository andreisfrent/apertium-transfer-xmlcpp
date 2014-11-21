#include <apertium_xml2cpp.h>
#include <string>
#include <set>
#include <sstream>

namespace apertium {
namespace xml2cpp {
GlobalLists::GlobalLists(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"def-list")) {
    HandleListDefinition(xml_child);
  }
}

GlobalLists::GlobalLists()
    : ASTNode() {
}

GlobalLists::~GlobalLists() {
}

void GlobalLists::HandleListDefinition(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"n", L"c"});
  const std::wstring& list_name = xml_node->GetMandatoryAttribute(L"n");

  if (lists_.find(list_name) != lists_.end()) {
    Error::Fatal(*xml_node, "Multiple definitions of list \"", list_name, "\".");
  }

  lists_.insert(std::make_pair(list_name, std::set<std::wstring>()));

  for (const XMLNode *xml_child : xml_node->GetChildrenByTag(L"list-item")) {
    HandleListElementDefinition(xml_child, list_name);
  }
}

void GlobalLists::HandleListElementDefinition(
    const XMLNode *xml_node, const std::wstring& list_name) {
  xml_node->EmitWarningOnUnknownAttributes({L"v", L"c"});
  const std::wstring& list_item = xml_node->GetMandatoryAttribute(L"v");
  lists_[list_name].insert(list_item);
}

void GlobalLists::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "List definitions:");
  for (const auto& kv : lists_) {
    std::wstringstream wss;
    wss << kv.first << L" = [";
    size_t item_index = 0;
    for (const std::wstring& list_item : kv.second) {
      wss << list_item;
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
