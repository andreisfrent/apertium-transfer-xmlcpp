#include <iostream>

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
  std::wcerr << L"XML-to-C++ compiler for structural transfer in Apertium." << std::endl;
  ASTNode *root = buildASTFromStdin();
  return 0;
}
