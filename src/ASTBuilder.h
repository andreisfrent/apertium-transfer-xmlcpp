#ifndef __APERTIUM_XML2CPP_AST_BUILDER_H
#define __APERTIUM_XML2CPP_AST_BUILDER_H

namespace apertium {
namespace xml2cpp {
class ASTBuilder {
 public:
  ASTBuilder();
 private:
  ASTBuilder(ASTBuilder&);
  ASTBuilder(ASTBuilder&&);
  ASTBuilder& operator=(ASTBuilder&);
  ASTBuilder& operator=(ASTBuilder&&);
};
} // namespace xml2cpp
} // namespace apertium

#endif
