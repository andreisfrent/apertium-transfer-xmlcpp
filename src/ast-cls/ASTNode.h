#ifndef __AST_CLASSES_AST_NODE_H
#define __AST_CLASSES_AST_NODE_H

namespace apertium {
namespace xml2cpp {
class ASTNode {
 public:
  ASTNode();
 private:
  ASTNode(ASTNode&);
  ASTNode(ASTNode&&);
  ASTNode& operator=(ASTNode&);
  ASTNode& operator=(ASTNode&&);
};
}; // namespace xml2cpp
}; // namespace apertium

#endif
