#include "ASTNode_Root.h"
#include "ASTNode.h"

#include <string>
#include <unordered_map>

namespace {
  const std::wstring& kDefaultRootTag(L"root");
  const int kDefaultRootLineNo = -1;
}

namespace apertium {
namespace xml2cpp {
ASTNode_Root::ASTNode_Root() : ASTNode() {
  // Set tag and line_no to some default values.
  set_tag(kDefaultRootTag);
  set_line_no(kDefaultRootLineNo);
}

void ASTNode_Root::Initialize(
    const std::unordered_map<std::wstring, std::wstring>& attrs) {
  // No initialization for this type of node.
}
} // namespace xml2cpp
} // namespace apertium
