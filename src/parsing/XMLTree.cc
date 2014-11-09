#include <apertium_xml2cpp.h>
#include <string>

namespace apertium {
namespace xml2cpp {
XMLTree::XMLTree() {
  root_ = new XMLNode(L"*");
  root_->set_line_no(-1);
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

const XMLNode *XMLTree::get_root() const {
  return root_;
}

} // namespace xml2cpp
} // namespace apertium
