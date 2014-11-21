#ifndef __APERTIUM_XML2CPP_VARIABLE_RVALUE_H
#define __APERTIUM_XML2CPP_VARIABLE_RVALUE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Variable_RValue : public RValue, public VariableBase {
 public:
  Variable_RValue(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif

