#include "ASTNode_Transfer.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Transfer::ASTNode_Transfer() : ASTNode() {
}

ASTNode_Transfer::~ASTNode_Transfer() {
}

void ASTNode_Transfer::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  // TODO
}
} // namespace xml2cpp
} // namespace apertium
