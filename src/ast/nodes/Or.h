#ifndef __APERTIUM_XML2CPP_OR_H
#define __APERTIUM_XML2CPP_OR_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Or : public Condition {
 public:
  Or(const XMLNode *xml_node);
  ~Or();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::vector<Condition*> children_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
