#include "ASTNode_Transfer.h"
#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
ASTNode_Transfer::ASTNode_Transfer() : ASTNode() {
}

ASTNode_Transfer::~ASTNode_Transfer() {
}

void ASTNode_Transfer::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  const auto& it = attrs.find(L"default");
  if (it == attrs.end() || it->second == L"lu") {
    operation_mode_ = kOperationMode_LU;
  } else if (it->second == L"chunk") {
    operation_mode_ = kOperationMode_CHUNK;
  } else {
    throw std::runtime_error("Error! Bad attributes for transfer node.");
  }
}
} // namespace xml2cpp
} // namespace apertium
