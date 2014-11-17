#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGEPOSTCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGEPOSTCHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class StagePostchunk : public Stage {
 public:
  StagePostchunk(const XMLNode *xml_node);
  ~StagePostchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
