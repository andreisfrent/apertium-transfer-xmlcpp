#include "ASTBuilder.h"

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
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
