#include "ASTNode_Postchunk.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Postchunk::ASTNode_Postchunk(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

ASTNode_Postchunk::~ASTNode_Postchunk() {
}
} // namespace xml2cpp
} // namespace apertium
