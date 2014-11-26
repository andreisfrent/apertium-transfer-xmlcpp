#ifndef __APERTIUM_XML2CPP_SUBSTRCMP_H
#define __APERTIUM_XML2CPP_SUBSTRCMP_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class SubstrCmp : public Condition {
 public:
  SubstrCmp(const XMLNode *xml_node);
  ~SubstrCmp();

  void SemanticCheck(const CompilationContext *ctx) const override;

  static const int kBegin;
  static const int kEnd;
  static const int kAnywhere;

 private:
  void HandleXMLTag(const XMLNode *xml_node);
  void HandleXMLChildren(const XMLNode *xml_node);
  void HandleXMLAttributes(const XMLNode *xml_node);

  RValue *op1_;
  RValue *op2_;
  bool caseless_;
  int where_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
