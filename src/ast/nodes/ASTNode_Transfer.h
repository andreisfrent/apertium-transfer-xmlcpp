#ifndef __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H
#define __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H

#include <string>
#include <unordered_map>

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Transfer : public ASTNode {
 public:
  ASTNode_Transfer();
  ~ASTNode_Transfer();

  void Initialize(
      const std::unordered_map<std::wstring, std::wstring>& attrs) override;
};
} // namespace xml2cpp
} // namespace apertium

#endif
