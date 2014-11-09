#ifndef __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H
#define __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Transfer : public ASTNode {
 public:
  ASTNode_Transfer();
  ~ASTNode_Transfer();

  const int kOperationMode_LU = 0;
  const int kOperationMode_CHUNK = 1;

  void Initialize(
      const std::unordered_map<std::wstring, std::wstring>& attrs) override;

 private:
  int operation_mode_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
