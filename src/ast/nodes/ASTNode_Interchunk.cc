#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_Interchunk::ASTNode_Interchunk(const XMLNode *xml_node)
    : ASTNode_Stage(xml_node) {
}

ASTNode_Interchunk::~ASTNode_Interchunk() {
}
} // namespace xml2cpp
} // namespace apertium
