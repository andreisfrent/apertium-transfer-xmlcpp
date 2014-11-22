#ifndef __APERTIUM_XML2CPP_OUT_H
#define __APERTIUM_XML2CPP_OUT_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Out : public Statement {
 public:
  Out(const XMLNode *xml_node);
  ~Out();

 private:
  std::vector<RValue*> values_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
