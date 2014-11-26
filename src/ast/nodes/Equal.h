#ifndef __APERTIUM_XML2CPP_EQUAL_H
#define __APERTIUM_XML2CPP_EQUAL_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Equal : public Condition {
 public:
  Equal(const XMLNode *xml_node);
  ~Equal();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  void HandleXMLChildren(const XMLNode *xml_node);
  void HandleXMLAttributes(const XMLNode *xml_node);

  RValue *op1_;
  RValue *op2_;
  bool caseless_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
