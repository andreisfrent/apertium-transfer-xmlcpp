#ifndef __APERTIUM_XML2CPP_AST_NODE_POSTCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_POSTCHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_Postchunk : public ASTNode_Stage {
 public:
  ASTNode_Postchunk(const XMLNode *xml_node);
  ~ASTNode_Postchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
