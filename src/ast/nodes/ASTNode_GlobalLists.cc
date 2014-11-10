#include <apertium_xml2cpp.h>
#include <string>
#include <set>
#include <sstream>

namespace apertium {
namespace xml2cpp {
ASTNode_GlobalLists::ASTNode_GlobalLists(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"def-list") {
      HandleListDefinition(xml_child);
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in lists definition section.");
    }
  }
}

ASTNode_GlobalLists::ASTNode_GlobalLists()
    : ASTNode() {
}

ASTNode_GlobalLists::~ASTNode_GlobalLists() {
}

void ASTNode_GlobalLists::HandleListDefinition(const XMLNode *xml_node) {
  if (xml_node->get_attrs().find(L"n") == xml_node->get_attrs().end()) {
    Error::Fatal("List name is missing.");
  }

  const std::wstring& list_name = xml_node->get_attrs().find(L"n")->second;
  if (lists_.find(list_name) != lists_.end()) {
    Error::Warning("Multiple definitions of list \"", list_name, "\".");
  }
  lists_.insert(std::make_pair(list_name, std::set<std::wstring>()));

  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"list-item") {
      HandleListElementDefinition(xml_child, list_name);
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in definition of list \"", list_name, "\".");
    }
  }
}

void ASTNode_GlobalLists::HandleListElementDefinition(
    const XMLNode *xml_node, const std::wstring& list_name) {
  if (xml_node->get_attrs().find(L"v") == xml_node->get_attrs().end()) {
    Error::Fatal("List item value is missing.");
  }

  const std::wstring& list_item = xml_node->get_attrs().find(L"v")->second;
  lists_[list_name].insert(list_item);
}

void ASTNode_GlobalLists::PrintLists() {
  Error::Debug("List definitions:");
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
    Error::Debug("  ", wss.str());
  }
}
} // namespace xml2cpp
} // namespace apertium
