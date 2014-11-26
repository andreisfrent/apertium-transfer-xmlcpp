#ifndef __APERTIUM_XML2CPP_LVALUE_H
#define __APERTIUM_XML2CPP_LVALUE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class LValue : public ASTNode {
 public:
  static LValue *FromXMLNode(const XMLNode *xml_node);

 protected:
  LValue(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
