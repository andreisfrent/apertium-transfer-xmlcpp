#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGEINTERCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGEINTERCHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class StageInterchunk : public Stage {
 public:
  StageInterchunk(const XMLNode *xml_node);
  ~StageInterchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
