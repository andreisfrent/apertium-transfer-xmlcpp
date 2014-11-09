#include "ASTNode_Postchunk.h"
#include "ASTNode.h"

#include <iostream>
#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Postchunk::ASTNode_Postchunk() : ASTNode() {
}

ASTNode_Postchunk::~ASTNode_Postchunk() {
}

void ASTNode_Postchunk::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  if (attrs.size() != 0) {
    std::wcerr << L"Extra attributes on <" << tag_ << L"> node." << std::endl;
  }
}
} // namespace xml2cpp
} // namespace apertium
