#ifndef __APERTIUM_XML2CPP_GETCASEFROM_H
#define __APERTIUM_XML2CPP_GETCASEFROM_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class GetCaseFrom : public RValue {
 public:
  GetCaseFrom(const XMLNode *xml_node);
  ~GetCaseFrom();

 private:
  int pos_;
  RValue *value_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

