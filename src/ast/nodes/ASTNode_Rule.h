#ifndef __APERTIUM_XML2CPP_AST_NODE_RULE_H
#define __APERTIUM_XML2CPP_AST_NODE_RULE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_Rule : public ASTNode {
 public:
  ASTNode_Rule(const XMLNode *xml_node);
  ~ASTNode_Rule();

  void PrintDebugInfo(const std::wstring& indentation = L"") const override;
  void HandleXMLNode_pattern(const XMLNode *xml_node);
  void HandleXMLNode_pattern_item(const XMLNode *xml_node);
  void HandleXMLNode_action(const XMLNode *xml_node);

 private:
  std::vector<std::wstring> pattern_; // cat refs.
  ASTNode_CodeBlock *code_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
