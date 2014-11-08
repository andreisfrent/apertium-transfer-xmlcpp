#ifndef __APERTIUM_XML2CPP_XML_TREE_H
#define __APERTIUM_XML2CPP_XML_TREE_H

#include <stack>
#include <string>

// Forward declaration.
namespace apertium {
namespace xml2cpp {
class XMLNode;
} // namespace xml2cpp
} // namespace apertium

namespace apertium {
namespace xml2cpp {
class XMLTree {
 public:
  XMLTree();
  ~XMLTree();

  XMLNode *Descend();
  XMLNode *Descend(const std::wstring& tag);
  XMLNode *Ascend();

 private:
  XMLNode *root_;
  std::stack<XMLNode*> current_path_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
