#include "ASTBuilder.h"

#include <iostream>
#include <libxml/xmlreader.h>
#include <string>

#include "ast-cls/ASTNode.h"

namespace apertium {
namespace xml2cpp {
ASTBuilder::ASTBuilder(int fd) {
  xmlReader_ = xmlReaderForFd(fd, NULL, NULL, 0);
  if (xmlReader_ == NULL) {
    FreeResources();
    throw std::wstring(L"Error! Could not initialize XML parser.");
  }
}

ASTBuilder::ASTBuilder(char *filename) {
  xmlReader_ = xmlReaderForFile(filename, NULL, 0);
}

void ASTBuilder::FreeResources() {
  if (xmlReader_ != NULL) {
    xmlFreeTextReader(xmlReader_);
    xmlReader_ = NULL;
  }
}

ASTBuilder::~ASTBuilder() {
  FreeResources();
}

ASTNode *ASTBuilder::Build() {
  // We assume the XML reader member is sane here.
  int ret = xmlTextReaderRead(xmlReader_);
  std::string indentation("");
  while (ret == 1) {
    int node_type = xmlTextReaderNodeType(xmlReader_);
    xmlChar * xml_tag = xmlTextReaderName(xmlReader_);
    if (node_type == XML_READER_TYPE_ELEMENT) {
      std::cout << indentation << "+ " << xml_tag << std::endl;
      indentation += "  ";
      if (xmlTextReaderIsEmptyElement(xmlReader_)) {
        indentation = indentation.substr(0, indentation.size() - 2);
        std::cout << indentation << "- " << xml_tag << std::endl;
      }
    }
    if (node_type == XML_READER_TYPE_END_ELEMENT) {
      indentation = indentation.substr(0, indentation.size() - 2);
      std::cout << indentation << "- " << xml_tag << std::endl;
    }

    // Advance to next node in XML stream.
    ret = xmlTextReaderRead(xmlReader_);
  }

  if (ret == -1) {
    throw std::wstring(L"Error! Could not parse input as XML.");
  }

  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
