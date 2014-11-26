#ifndef __APERTIUM_XML2CPP_STATEMENT_H
#define __APERTIUM_XML2CPP_STATEMENT_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Statement : public ASTNode {
 public:
  static Statement *FromXMLNode(const XMLNode *xml_node);

 protected:
  Statement(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
