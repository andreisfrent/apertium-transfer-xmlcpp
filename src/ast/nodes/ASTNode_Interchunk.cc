#include "ASTNode_Interchunk.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Interchunk::ASTNode_Interchunk(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

ASTNode_Interchunk::~ASTNode_Interchunk() {
}
} // namespace xml2cpp
} // namespace apertium
