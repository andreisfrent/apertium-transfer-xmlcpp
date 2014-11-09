#include "ASTNode_Transfer.h"
#include "ASTNode.h"

#include <iostream>

namespace apertium {
namespace xml2cpp {
ASTNode_Transfer::ASTNode_Transfer() : ASTNode() {
}

ASTNode_Transfer::~ASTNode_Transfer() {
}

void ASTNode_Transfer::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  SetDefaultAttrs();
  for (const auto& kv : attrs) {
    if (kv.first == L"default") HandleAttr_default(kv.second);
    else {
      std::wcerr << L"Unknown attribute '" << kv.first << L"' of <" << tag_
          << L"> tag." << std::endl;
    }
  }
}

void ASTNode_Transfer::SetDefaultAttrs() {
  operation_mode_ = kOperationMode_LU;
}

void ASTNode_Transfer::HandleAttr_default(const std::wstring& value) {
  if (value == L"lu") {
    operation_mode_ = kOperationMode_LU;
  } else if (value == L"chunk") {
    operation_mode_ = kOperationMode_CHUNK;
  } else {
    throw std::runtime_error("Error! Bad value for 'default' attribute of <transfer> node.");
  }
}
} // namespace xml2cpp
} // namespace apertium
