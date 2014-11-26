#ifndef __APERTIUM_XML2CPP_CONCAT_H
#define __APERTIUM_XML2CPP_CONCAT_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Concat : public RValue {
 public:
  Concat(const XMLNode *xml_node);
  ~Concat();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::vector<RValue*> values_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

