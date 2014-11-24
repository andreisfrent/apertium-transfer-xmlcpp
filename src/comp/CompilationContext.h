#ifndef _APERTIUM_XML2CPP_COMPILATION_CONTEXT_H
#define _APERTIUM_XML2CPP_COMPILATION_CONTEXT_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class AST;
class CompilationContext {
 public:
  CompilationContext(AST *ast);

 private:
  AST *ast_;
};
} // namespace apertium
} // namespace xml2cpp

#endif
