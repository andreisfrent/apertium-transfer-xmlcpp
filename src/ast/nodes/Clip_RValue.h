#ifndef __APERTIUM_XML2CPP_CLIP_RVALUE_H
#define __APERTIUM_XML2CPP_CLIP_RVALUE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Clip_RValue : public RValue, public ClipBase {
 public:
  Clip_RValue(const XMLNode *xml_node);
  void SemanticCheck(const CompilationContext *ctx) const override;
};
} // namespace xml2cpp
} // namespace apertium

#endif

