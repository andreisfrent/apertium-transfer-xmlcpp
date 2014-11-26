#ifndef __APERTIUM_XML2CPP_CONDITION_H
#define __APERTIUM_XML2CPP_CONDITION_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Condition : public ASTNode {
 public:
  static Condition *FromXMLNode(const XMLNode *xml_node);

 protected:
  Condition(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
