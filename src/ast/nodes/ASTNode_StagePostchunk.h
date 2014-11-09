#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGEPOSTCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGEPOSTCHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_StagePostchunk : public ASTNode_Stage {
 public:
  ASTNode_StagePostchunk(const XMLNode *xml_node);
  ~ASTNode_StagePostchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
