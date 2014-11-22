#ifndef __APERTIUM_XML2CPP_MLU_H
#define __APERTIUM_XML2CPP_MLU_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Mlu : public RValue {
 public:
  Mlu(const XMLNode *xml_node);
  ~Mlu();

 private:
  std::vector<Lu*> values_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

