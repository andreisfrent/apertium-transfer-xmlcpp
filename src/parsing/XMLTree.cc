#include "XMLTree.h"

#include <string>

#include "XMLNode.h"

namespace apertium {
namespace xml2cpp {
XMLTree::XMLTree() {
  root_ = new XMLNode(L"document");
  current_path_.push(root_);
}

XMLTree::~XMLTree() {
  delete root_;
}

XMLNode *XMLTree::Descend(const std::wstring& tag) {
  XMLNode *new_node = Descend();
  new_node->set_tag(tag);
  return new_node;
}

XMLNode *XMLTree::Descend() {
  XMLNode *new_node = new XMLNode();
  current_path_.top()->AddChild(new_node);
  current_path_.push(new_node);
  return new_node;
}

XMLNode *XMLTree::Ascend() {
  XMLNode *ret = current_path_.top();
  current_path_.pop();
  return ret;
}

} // namespace xml2cpp
} // namespace apertium
