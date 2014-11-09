#include "ASTNode_Root.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Root::ASTNode_Root() : ASTNode() {
}

ASTNode_Root::~ASTNode_Root() {
}

void ASTNode_Root::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  // Do nothing.
}
} // namespace xml2cpp
} // namespace apertium
