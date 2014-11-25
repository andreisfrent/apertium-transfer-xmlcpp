#ifndef __APERTIUM_XML2CPP_AND_H
#define __APERTIUM_XML2CPP_AND_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class And : public Condition {
 public:
  And(const XMLNode *xml_node);
  ~And();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::vector<Condition*> children_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
