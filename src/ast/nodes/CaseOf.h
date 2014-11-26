#ifndef __APERTIUM_XML2CPP_CASEOF_H
#define __APERTIUM_XML2CPP_CASEOF_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class CaseOf : public RValue {
 public:
  CaseOf(const XMLNode *xml_node);

  static const std::wstring kSourceLanguage;
  static const std::wstring kTargetLanguage;

  void SemanticCheck(const CompilationContext *ctx) const override;
 private:
  int pos_;
  std::wstring side_;
  std::wstring part_;
};
} // namespace xml2cpp
} // namespace apertium

#endif

