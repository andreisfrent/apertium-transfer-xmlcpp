#include "ASTNode_SectionDefCats.h"
#include "ASTNode.h"

#include <iostream>
#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_SectionDefCats::ASTNode_SectionDefCats() : ASTNode() {
}

ASTNode_SectionDefCats::~ASTNode_SectionDefCats() {
}

void ASTNode_SectionDefCats::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  if (attrs.size() != 0) {
    std::wcerr << L"Extra attributes on <" << tag_ << L"> node." << std::endl;
  }
}
} // namespace xml2cpp
} // namespace apertium
