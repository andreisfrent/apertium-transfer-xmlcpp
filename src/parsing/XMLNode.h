#ifndef __APERTIUM_XML2CPP_XML_NODE_H
#define __APERTIUM_XML2CPP_XML_NODE_H

#include <string>
#include <unordered_map>
#include <vector>

namespace apertium {
namespace xml2cpp {
class XMLNode {
 public:
  explicit XMLNode(const std::wstring& tag);
  XMLNode();
  ~XMLNode();

  void AddAttribute(const std::wstring& key, const std::wstring& value);
  void AddChild(XMLNode *child);
  bool IsLeaf() const;

  void set_tag(const std::wstring& tag);
  const std::wstring& get_tag() const;
  const std::unordered_map<std::wstring, std::wstring>& get_attrs() const;
  void set_line_no(int line_no);
  int get_line_no() const;
  const std::vector<XMLNode*>& get_children() const;

 private:
  std::unordered_map<std::wstring, std::wstring> attrs_;
  std::vector<XMLNode*> children_;
  std::wstring tag_;
  int line_no_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
