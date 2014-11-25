#ifndef __APERTIUM_XML2CPP_APPEND_H
#define __APERTIUM_XML2CPP_APPEND_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Append : public Statement {
 public:
  Append(const XMLNode *xml_node);
  ~Append();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::wstring var_name_;
  std::vector<RValue*> values_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
