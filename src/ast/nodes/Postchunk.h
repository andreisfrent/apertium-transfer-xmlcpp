#ifndef __APERTIUM_XML2CPP_POSTCHUNK_H
#define __APERTIUM_XML2CPP_POSTCHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Postchunk : public Stage {
 public:
  Postchunk(const XMLNode *xml_node);

  void SemanticCheck(const CompilationContext *ctx) const override;
};
} // namespace xml2cpp
} // namespace apertium

#endif
