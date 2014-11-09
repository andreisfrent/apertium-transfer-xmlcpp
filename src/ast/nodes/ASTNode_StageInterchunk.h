#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGEINTERCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGEINTERCHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_StageInterchunk : public ASTNode_Stage {
 public:
  ASTNode_StageInterchunk(const XMLNode *xml_node);
  ~ASTNode_StageInterchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
