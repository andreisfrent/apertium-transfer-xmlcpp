#include <apertium_xml2cpp.h>
#include <iostream>
#include <libxml/xmlreader.h>
#include <string>

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
    AST ast(xml_tree);
    ast.PrintDebugInfo();
  } catch (std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }

  xmlCleanupParser();
  return 0;
}
