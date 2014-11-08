#ifndef __APERTIUM_XML2CPP_AST_BUILDER_H
#define __APERTIUM_XML2CPP_AST_BUILDER_H

#include <libxml/xmlreader.h>
#include <string>

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
  ASTNode *Build();

  /// This method is directly called by the destructor and frees any used
  /// resources. Its main purpose is to be able to free resources when throwing
  /// an exception from the constructor.
  void FreeResources();

 private:
  ASTBuilder(ASTBuilder&);
  ASTBuilder(ASTBuilder&&);
  ASTBuilder& operator=(ASTBuilder&);
  ASTBuilder& operator=(ASTBuilder&&);

  std::wstring GetCurrentElementName();

  xmlTextReaderPtr xmlReader_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
