#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_Postchunk::ASTNode_Postchunk(const XMLNode *xml_node)
    : ASTNode_Stage(xml_node) {
}

ASTNode_Postchunk::~ASTNode_Postchunk() {
}
} // namespace xml2cpp
} // namespace apertium
