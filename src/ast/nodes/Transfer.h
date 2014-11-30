#ifndef __APERTIUM_XML2CPP_TRANSFER_H
#define __APERTIUM_XML2CPP_TRANSFER_H

#include <string>

namespace apertium {
namespace xml2cpp {
class CompilationContext;
class XMLNode;
class Transfer : public Stage {
 public:
  Transfer(const XMLNode *xml_node);

  static const std::wstring kLu;
  static const std::wstring kChunk;

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::wstring transfer_mode_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
