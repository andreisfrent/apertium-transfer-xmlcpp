#include "ASTNode_Transfer.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Transfer::ASTNode_Transfer(const XMLNode *xml_node)
    : ASTNode(xml_node) {
}

ASTNode_Transfer::~ASTNode_Transfer() {
}
} // namespace xml2cpp
} // namespace apertium
