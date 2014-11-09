#include "ASTNode_Root.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Root::ASTNode_Root(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

ASTNode_Root::~ASTNode_Root() {
}
} // namespace xml2cpp
} // namespace apertium
