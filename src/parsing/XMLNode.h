#ifndef __APERTIUM_XML2CPP_XML_NODE_H
#define __APERTIUM_XML2CPP_XML_NODE_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>

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
  const std::vector<XMLNode*>& GetChildrenByTag(const std::wstring& tag) const;

  const std::wstring& GetMandatoryAttribute(
      const std::wstring& attribute) const;
  const std::wstring& GetOptionalAttribute(
      const std::wstring& attribute, const std::wstring& default_value) const;

  template<typename T>
  T GetMandatoryAttributeAs(const std::wstring& attribute) const {
    T result;
    std::wstringstream wss;
    const std::wstring& attr_val = GetMandatoryAttribute(attribute);
    wss << attr_val;
    wss >> result;
    return result;
  }

  template<typename T>
  T GetOptionalAttributeAs(
      const std::wstring& attribute, const std::wstring& default_value) const {
    T result;
    std::wstringstream wss;
    const std::wstring& attr_val = GetOptionalAttribute(attribute, default_value);
    wss << attr_val;
    wss >> result;
    return result;
  }

 private:
  std::unordered_map<std::wstring, std::wstring> attrs_;
  std::vector<XMLNode*> children_;
  std::unordered_map<std::wstring, std::vector<XMLNode*>> children_by_tag_;
  std::wstring tag_;
  int line_no_;
};
} // namespace xml2cpp
} // namespace apertium

std::wostream& operator <<(std::wostream& stream, const apertium::xml2cpp::XMLNode& xml_node);
#endif
