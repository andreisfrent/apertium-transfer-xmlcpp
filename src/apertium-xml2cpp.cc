#include "ASTBuilder.h"
#include "ast-cls/ASTNode.h"

using apertium::xml2cpp::ASTNode;
using apertium::xml2cpp::ASTBuilder;

ASTNode *buildASTFromStdin() {
  ASTBuilder builder(0);
  ASTNode *root = builder.build();
  return root;
}

int main(int argc, char *argv[]) {
  ASTNode *root = buildASTFromStdin();
  return 0;
}
