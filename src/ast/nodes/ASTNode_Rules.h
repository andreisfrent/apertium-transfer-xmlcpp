#ifndef __APERTIUM_XML2CPP_AST_NODE_RULES_H
#define __APERTIUM_XML2CPP_AST_NODE_RULES_H

#include <apertium_xml2cpp.h>
#include <string>
#include <vector>

namespace apertium {
namespace xml2cpp {
class Rules : public ASTNode {
 public:
  Rules(const XMLNode *xml_node);
  ~Rules();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  std::vector<Rule*> rules_;

  void HandleRuleDefinition(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
