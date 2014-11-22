#ifndef __APERTIUM_XML2CPP_B_H
#define __APERTIUM_XML2CPP_B_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class B : public RValue {
 public:
  B(const XMLNode *xml_node);

 private:
  std::wstring pos_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

