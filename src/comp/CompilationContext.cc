#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
CompilationContext::CompilationContext(AST *ast)
    : ast_(ast) {
}

void CompilationContext::AssertVariable(
    const ASTNode *calling_node, const std::wstring& name) const {
  Error::Assert(
      ast_->get_root()->get_global_variables()->HasVariable(name),
      *calling_node, "Variable \"", name, "\" not defined.");
}

void CompilationContext::AssertList(
    const ASTNode *calling_node, const std::wstring& name) const {
  Error::Assert(
      ast_->get_root()->get_global_lists()->HasList(name),
      *calling_node, "List \"", name, "\" not defined.");
}
} // namespace apertium
} // namespace xml2cpp
