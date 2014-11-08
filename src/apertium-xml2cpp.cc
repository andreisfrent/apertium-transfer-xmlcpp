#include <iostream>
#include <libxml/xmlreader.h>
#include <memory>
#include <string>

#include "parsing/XMLParser.h"
#include "parsing/XMLTree.h"
#include "ast/nodes/ASTNode.h"
#include "ast/AST.h"

using apertium::xml2cpp::ASTNode;
using apertium::xml2cpp::XMLParser;
using apertium::xml2cpp::XMLTree;
using apertium::xml2cpp::AST;

int main(int argc, char *argv[]) {
  std::wcerr << L"XML-to-C++ compiler for structural transfer in Apertium." << std::endl;
  xmlInitParser();

  try {
    XMLParser xml_parser(0);
    XMLTree xml_tree;
    xml_parser.Parse(&xml_tree);
    std::unique_ptr<AST> ast(AST::FromXMLTree(xml_tree));
  } catch (std::wstring& ex) {
    std::wcerr << ex << std::endl;
  }

  xmlCleanupParser();
  return 0;
}
