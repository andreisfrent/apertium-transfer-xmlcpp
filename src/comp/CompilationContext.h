#ifndef _APERTIUM_XML2CPP_COMPILATION_CONTEXT_H
#define _APERTIUM_XML2CPP_COMPILATION_CONTEXT_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class AST;
class ASTNode;
class SymbolTable;
class CompilationContext {
 public:
  CompilationContext(AST *ast);
  ~CompilationContext();

  void AssertVariable(const ASTNode *calling_node, const std::wstring& name) const;
  void AssertList(const ASTNode *calling_node, const std::wstring& name) const;
  void AssertMacro(const ASTNode *calling_node, const std::wstring& name, int param_count) const;

  SymbolTable *get_symbol_table();
 private:
  AST *ast_;
  SymbolTable *symbol_table_;
};
} // namespace apertium
} // namespace xml2cpp

#endif
