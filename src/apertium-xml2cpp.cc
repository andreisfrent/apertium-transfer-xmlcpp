#include <iostream>
#include <libxml/xmlreader.h>
#include <memory>
#include <string>

#include "ASTBuilder.h"
#include "ast-cls/ASTNode.h"

using apertium::xml2cpp::ASTNode;
using apertium::xml2cpp::ASTBuilder;

int main(int argc, char *argv[]) {
  std::wcerr << L"XML-to-C++ compiler for structural transfer in Apertium." << std::endl;
  xmlInitParser();

  try {
    ASTBuilder builder(0);
    std::unique_ptr<ASTNode> root(builder.Build());
  } catch (std::wstring& ex) {
    std::wcerr << ex << std::endl;
  }
  xmlCleanupParser();
  return 0;
}
