#include "ASTBuilder.h"

#include <libxml/xmlreader.h>

#include "ast-cls/ASTNode.h"

namespace apertium {
namespace xml2cpp {
ASTBuilder::ASTBuilder(int fd) {
  xmlInitParser();
  this->xmlReader_ = xmlReaderForFd(fd, NULL, NULL, 0);
}

ASTBuilder::ASTBuilder(char *filename) {
  xmlInitParser();
  this->xmlReader_ = xmlReaderForFile(filename, NULL, 0);
}

ASTBuilder::~ASTBuilder() {
  xmlFreeTextReader(this->xmlReader_);
  xmlCleanupParser();
}

ASTNode *ASTBuilder::build() {
  // TODO(asfrent): walk the tree, build the abstract syntax tree.
  return NULL;
}
} // namespace xml2cpp
} // namespace apertium
