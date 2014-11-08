#include "ASTNode_Root.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Root::ASTNode_Root() : ASTNode() {
}

void ASTNode_Root::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  // No initialization for this type of node.
}
} // namespace xml2cpp
} // namespace apertium
