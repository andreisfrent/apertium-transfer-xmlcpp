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
  ~XMLNode();

  void AddAttribute(const std::wstring& key, const std::wstring& value);
  void AddChild(XMLNode *child);
  bool IsLeaf();

 private:
  std::unordered_map<std::wstring, std::wstring> attrs_;
  std::vector<XMLNode*> children_;
  std::wstring tag_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
