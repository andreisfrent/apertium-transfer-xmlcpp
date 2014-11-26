#ifndef __APERTIUM_XML2CPP_LET_H
#define __APERTIUM_XML2CPP_LET_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Let : public Statement {
 public:
  Let(const XMLNode *xml_node);
  ~Let();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  LValue *left_;
  RValue *right_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
