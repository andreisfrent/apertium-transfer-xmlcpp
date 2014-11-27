#ifndef __APERTIUM_XML2CPP_CALLMACRO_H
#define __APERTIUM_XML2CPP_CALLMACRO_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class CallMacro : public Statement {
 public:
  CallMacro(const XMLNode *xml_node);

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::wstring macro_;
  std::vector<int> args_;

  void HandleXMLAttributes(const XMLNode *xml_node);
  void ExtractArgumentsFromXMLNode(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
