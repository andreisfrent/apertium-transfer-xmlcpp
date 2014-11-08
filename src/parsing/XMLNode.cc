#include "XMLNode.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace apertium {
namespace xml2cpp {
XMLNode::XMLNode(const std::wstring& tag) {
  tag_ = tag;
}

XMLNode::XMLNode() {
}

XMLNode::~XMLNode() {
  for (XMLNode *child : children_) {
    delete child;
  }
}

void XMLNode::AddAttribute(const std::wstring& key, const std::wstring& value) {
  attrs_[key] = value;
}

void XMLNode::AddChild(XMLNode *child) {
  children_.push_back(child);
}

bool XMLNode::IsLeaf() const {
  return children_.size() == 0;
}

void XMLNode::set_tag(const std::wstring& tag) {
  tag_ = tag;
}

const std::wstring& XMLNode::get_tag() const {
  return tag_;
}

const std::unordered_map<std::wstring, std::wstring>& XMLNode::get_attrs() const {
  return attrs_;
}
} // namespace xml2cpp
} // namespace apertium
