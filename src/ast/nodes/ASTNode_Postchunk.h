#ifndef __APERTIUM_XML2CPP_AST_NODE_POSTCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_POSTCHUNK_H

#include <string>
#include <unordered_map>

#include "ASTNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode_Postchunk : public ASTNode {
 public:
  ASTNode_Postchunk();
  ~ASTNode_Postchunk();

  void Initialize(
      const std::unordered_map<std::wstring, std::wstring>& attrs) override;
};
} // namespace xml2cpp
} // namespace apertium

#endif
