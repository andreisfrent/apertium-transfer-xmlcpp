#ifndef __APERTIUM_XML2CPP_VARIABLE_BASE_H
#define __APERTIUM_XML2CPP_VARIABLE_BASE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class VariableBase {
 protected:
  VariableBase(const XMLNode *xml_node);
  std::wstring name_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

