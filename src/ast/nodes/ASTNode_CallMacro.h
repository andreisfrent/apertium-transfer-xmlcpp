#ifndef __APERTIUM_XML2CPP_AST_NODE_CALLMACRO_H
#define __APERTIUM_XML2CPP_AST_NODE_CALLMACRO_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_CallMacro : public Statement {
 public:
  ASTNode_CallMacro(const XMLNode *xml_node);
  ~ASTNode_CallMacro();

 private:
  std::wstring macro_;
  std::vector<int> args_;

  void HandleXMLAttributes(const XMLNode *xml_node);
  void ExtractArgumentsFromXMLNode(const XMLNode *xml_node);
  void HandleArgumentNode(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
