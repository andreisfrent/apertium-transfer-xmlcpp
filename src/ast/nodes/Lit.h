#ifndef __APERTIUM_XML2CPP_LIT_H
#define __APERTIUM_XML2CPP_LIT_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Lit : public RValue {
 public:
  Lit(const XMLNode *xml_node);
  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::wstring value_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

