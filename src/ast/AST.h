#ifndef __APERTIUM_XML2CPP_AST_H
#define __APERTIUM_XML2CPP_AST_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class AST {
 public:
  AST(const XMLTree& xml_tree);
  ~AST();

  void PrintDebugInfo() const;
  void SemanticCheck(const CompilationContext *ctx) const;
  void GenerateCode(CompilationContext *ctx) const;

  const Stage *get_root() const;

 private:
  Stage *stage_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
