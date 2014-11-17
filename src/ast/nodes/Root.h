#ifndef __APERTIUM_XML2CPP_AST_NODE_ROOT_H
#define __APERTIUM_XML2CPP_AST_NODE_ROOT_H

#include <apertium_xml2cpp.h>
#include <string>

namespace apertium {
namespace xml2cpp {
class Root : public ASTNode {
 public:
  Root(const XMLNode *xml_node);
  ~Root();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  Stage *stage_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
