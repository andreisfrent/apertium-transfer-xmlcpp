#ifndef __APERTIUM_XML2CPP_BEGINSWITH_H
#define __APERTIUM_XML2CPP_BEGINSWITH_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class BeginsWith : public Condition {
 public:
  BeginsWith(const XMLNode *xml_node);
  ~BeginsWith();

 private:
  void HandleXMLChildren(const XMLNode *xml_node);
  void HandleXMLAttributes(const XMLNode *xml_node);

  LValue *op1_;
  LValue *op2_;
  bool caseless_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
