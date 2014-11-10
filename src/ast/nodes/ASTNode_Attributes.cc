#include <apertium_xml2cpp.h>
#include <string>
#include <set>
#include <sstream>

namespace apertium {
namespace xml2cpp {
ASTNode_Attributes::ASTNode_Attributes(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"def-attr") {
      HandleAttrDefinition(xml_child);
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in attributes definition section.");
    }
  }
}

ASTNode_Attributes::~ASTNode_Attributes() {
}

void ASTNode_Attributes::HandleAttrDefinition(const XMLNode *xml_node) {
  if (xml_node->get_attrs().find(L"n") == xml_node->get_attrs().end()) {
    Error::Fatal("Attribute name is missing.");
  }

  const std::wstring& attribute = xml_node->get_attrs().find(L"n")->second;
  if (attributes_.find(attribute) != attributes_.end()) {
    Error::Warning("Multiple definitions of attribute \"", attribute, "\".");
  }
  attributes_.insert(std::make_pair(attribute, std::set<std::wstring>()));

  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"attr-item") {
      HandleAttrItemDefinition(xml_child, attribute);
    } else {
      Error::Fatal("Unexpected <", xml_child->get_tag(), "> in definition of attribute \"", attribute, "\".");
    }
  }
}

void ASTNode_Attributes::HandleAttrItemDefinition(
    const XMLNode *xml_node, const std::wstring& attribute) {
  if (xml_node->get_attrs().find(L"tags") == xml_node->get_attrs().end()) {
    Error::Fatal("Attribute item tags missing.");
  }

  const std::wstring& attribute_item = xml_node->get_attrs().find(L"tags")->second;
  attributes_[attribute].insert(attribute_item);
}

void ASTNode_Attributes::PrintDebugInfo(const std::wstring& indentation) const {
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
} // namespace xml2cpp
} // namespace apertium
