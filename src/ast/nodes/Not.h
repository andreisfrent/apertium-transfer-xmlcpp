#ifndef __APERTIUM_XML2CPP_NOT_H
#define __APERTIUM_XML2CPP_NOT_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Not : public Condition {
 public:
  Not(const XMLNode *xml_node);
  ~Not();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  Condition *condition_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
