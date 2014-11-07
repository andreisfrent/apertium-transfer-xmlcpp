#ifndef __APERTIUM_XML2CPP_AST_BUILDER_H
#define __APERTIUM_XML2CPP_AST_BUILDER_H

#include <libxml/xmlreader.h>

// Forward class declaration.
namespace apertium {
namespace xml2cpp {
class ASTNode;
} // xml2cpp
} // apertium

namespace apertium {
namespace xml2cpp {
class ASTBuilder {
 public:
  /// Construct the builder from a file descriptor (to be used whenever the XML
  /// is fed to stdin).
  explicit ASTBuilder(int fd);

  /// Construct the builder from a file.
  explicit ASTBuilder(char *filename);

  /// Destructor.
  ~ASTBuilder();

  /// Build the abstract syntax tree and returns its root node.
  ASTNode *build();

 private:
  ASTBuilder(ASTBuilder&);
  ASTBuilder(ASTBuilder&&);
  ASTBuilder& operator=(ASTBuilder&);
  ASTBuilder& operator=(ASTBuilder&&);

  xmlTextReaderPtr xmlReader_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
