#include <apertium_xml2cpp.h>
#include <iostream>
#include <libxml/xmlreader.h>
#include <string>

using apertium::xml2cpp::ASTNode;
using apertium::xml2cpp::XMLParser;
using apertium::xml2cpp::XMLTree;
using apertium::xml2cpp::AST;
using apertium::xml2cpp::CompilationContext;

int main(int argc, char *argv[]) {
  std::wcerr << L"XML-to-C++ compiler for structural transfer in Apertium." << std::endl;
  xmlInitParser();

  XMLParser xml_parser(0);
  XMLTree xml_tree;
  xml_parser.Parse(&xml_tree);
  AST ast(xml_tree);
  CompilationContext ctx(&ast);
  ast.SemanticCheck(&ctx);
  ast.GenerateCode(&ctx);

  xmlCleanupParser();
  return 0;
}
