#ifndef __APERTIUM_XML2CPP_CHUNK_H
#define __APERTIUM_XML2CPP_CHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Chunk : public RValue {
 public:
  Chunk(const XMLNode *xml_node);
  ~Chunk();

  void SemanticCheck(const CompilationContext *ctx) const override;

 private:
  std::vector<RValue*> tags_;
  std::vector<RValue*> values_;

  void ExtractTags(const XMLNode *xml_node);
  void ExtractValues(const XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif

