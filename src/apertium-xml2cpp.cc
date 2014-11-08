#include <iostream>
#include <libxml/xmlreader.h>
#include <memory>
#include <string>

#include "parsing/XMLParser.h"
#include "ast-cls/ASTNode.h"

using apertium::xml2cpp::ASTNode;
using apertium::xml2cpp::XMLParser;

int main(int argc, char *argv[]) {
  std::wcerr << L"XML-to-C++ compiler for structural transfer in Apertium." << std::endl;
  xmlInitParser();

  try {
    XMLParser xml_parser(0);
    xml_parser.Parse();
  } catch (std::wstring& ex) {
    std::wcerr << ex << std::endl;
  }

  xmlCleanupParser();
  return 0;
}
