#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Rule::Rule(const XMLNode *xml_node)
    : ASTNode(xml_node) {

  const std::vector<XMLNode*>& pattern_nodes = xml_node->GetChildrenByTag(L"pattern");
  const std::vector<XMLNode*>& action_nodes = xml_node->GetChildrenByTag(L"action");

  if (xml_node->get_children().size() != 2) {
    Error::Fatal(*xml_node, "Rule should only have two children nodes.");
  }

  if (pattern_nodes.empty()) {
    Error::Fatal(*xml_node, "Rule does not contain a <pattern> tag.");
  }

  if (action_nodes.empty()) {
    Error::Fatal(*xml_node, "Rule does not contain a <action> tag.");
  }

  if (pattern_nodes.size() > 1) {
    Error::Fatal(*xml_node, "Multiple <pattern> nodes defined inside <rule>.");
  }

  if (action_nodes.size() > 1) {
    Error::Fatal(*xml_node, "Multiple <action> nodes defined inside <rule>.");
  }

  HandleXMLNode_pattern(pattern_nodes[0]);
  HandleXMLNode_action(action_nodes[0]);
}

Rule::~Rule() {
  if (code_) delete code_;
}

void Rule::PrintDebugInfo(const std::wstring& indentation) const {
  std::wstringstream wss;
  wss << L"pattern: [";
  size_t item_index = 0;
  for (const std::wstring& pattern_item : pattern_) {
    wss << pattern_item;
    if (item_index + 1 < pattern_.size()) {
      wss << L", ";
    }
    ++item_index;
  }
  wss << L"]";
  Error::Debug(indentation, "  ", wss.str());
}

void Rule::HandleXMLNode_pattern(const XMLNode *xml_node) {
  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"pattern-item") {
      HandleXMLNode_pattern_item(xml_child);
    } else {
      Error::Fatal(*xml_child, "Unexpected ", xml_child->get_tag(), " inside <pattern>.");
    }
  }
}

void Rule::HandleXMLNode_pattern_item(const XMLNode *xml_node) {
  if (xml_node->get_children().size() > 0) {
    Error::Fatal(*xml_node, "Unexpected children for <pattern-item>.");
  }

  const auto& name_attr = xml_node->get_attrs().find(L"n");
  if (name_attr == xml_node->get_attrs().end()) {
    Error::Fatal(*xml_node, "No pattern item name supplied.");
  }

  pattern_.push_back(name_attr->second);
}

void Rule::HandleXMLNode_action(const XMLNode *xml_node) {
  code_ = new CodeBlock(xml_node);
}
} // namespace xml2cpp
} // namespace apertium
