#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

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
  children_by_tag_[child->get_tag()].push_back(child);
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

void XMLNode::set_line_no(int line_no) {
  line_no_ = line_no;
}

int XMLNode::get_line_no() const {
  return line_no_;
}

const std::vector<XMLNode*>& XMLNode::get_children() const {
  return children_;
}

const std::vector<XMLNode*>& XMLNode::GetChildrenByTag(const std::wstring& tag) const {
  static std::vector<XMLNode*> empty_vector;
  const auto& it = children_by_tag_.find(tag);
  if (it != children_by_tag_.end()) {
    return it->second;
  } else {
    return empty_vector;
  }
}
} // namespace xml2cpp
} // namespace apertium

std::wostream& operator <<(std::wostream& stream, const apertium::xml2cpp::XMLNode& xml_node) {
  stream << "Line " << xml_node.get_line_no() << " [<" << xml_node.get_tag() << ">]: ";
  return stream;
}
