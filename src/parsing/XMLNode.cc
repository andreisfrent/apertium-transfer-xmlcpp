#include "XMLNode.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace apertium {
namespace xml2cpp {
XMLNode::XMLNode(const std::wstring& tag) {
  tag_ = tag;
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

bool XMLNode::IsLeaf() {
  return children_.size() == 0;
}
} // namespace xml2cpp
} // namespace apertium
