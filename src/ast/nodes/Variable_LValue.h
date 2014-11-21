#ifndef __APERTIUM_XML2CPP_VARIABLE_LVALUE_H
#define __APERTIUM_XML2CPP_VARIABLE_LVALUE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Variable_LValue : public LValue, public VariableBase {
 public:
  Variable_LValue(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif

