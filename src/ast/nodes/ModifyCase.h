#ifndef __APERTIUM_XML2CPP_MODIFYCASE_H
#define __APERTIUM_XML2CPP_MODIFYCASE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ModifyCase : public Statement {
 public:
  ModifyCase(const XMLNode *xml_node);
  ~ModifyCase();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  LValue *left_;
  RValue *right_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
