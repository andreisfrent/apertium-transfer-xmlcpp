#ifndef __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H
#define __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
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
