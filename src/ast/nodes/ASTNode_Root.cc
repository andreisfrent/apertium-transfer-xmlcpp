#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
ASTNode_Root::ASTNode_Root(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  // We need to deal with only one transfer stage.
  if (xml_node->get_children().size() != 1) {
    Error::Fatal(L"XML root node has more than one child.");
  }

  const XMLNode *xml_child = xml_node->get_children().at(0);

  stage_ = NULL;
  const std::wstring& xml_root_tag = xml_node->get_tag();
  if (xml_root_tag == L"transfer") {
    stage_ = new ASTNode_Transfer(xml_child);
  } else if (xml_root_tag == L"interchunk") {
    stage_ = new ASTNode_Interchunk(xml_child);
  } else if (xml_root_tag == L"postchunk") {
    stage_ = new ASTNode_Postchunk(xml_child);
  } else {
    Error::Fatal(L"Transfer stage unknown (should be one of <transfer>, <interchunk>, <postchunk>).");
  }
}

ASTNode_Root::~ASTNode_Root() {
}
} // namespace xml2cpp
} // namespace apertium
