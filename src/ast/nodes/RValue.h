#ifndef __APERTIUM_XML2CPP_RVALUE_H
#define __APERTIUM_XML2CPP_RVALUE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class RValue : public ASTNode {
 public:
  static RValue *FromXMLNode(const XMLNode *xml_node);

 protected:
  RValue(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
