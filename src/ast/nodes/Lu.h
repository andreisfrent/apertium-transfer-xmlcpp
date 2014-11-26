#ifndef __APERTIUM_XML2CPP_LU_H
#define __APERTIUM_XML2CPP_LU_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Lu : public RValue {
 public:
  Lu(const XMLNode *xml_node);
  ~Lu();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::vector<RValue*> values_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

