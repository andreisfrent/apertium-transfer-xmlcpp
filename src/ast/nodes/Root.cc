#include <apertium_xml2cpp.h>
#include <string>
#include <unordered_map>

namespace apertium {
namespace xml2cpp {
Root::Root(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  if (xml_node->get_children().size() != 1) {
    Error::Fatal(*xml_node, L"XML root node has more than one child.");
  }

  const XMLNode *xml_child = xml_node->get_children().at(0);
  const std::wstring& xml_child_tag = xml_child->get_tag();

  stage_ = NULL;
  if (xml_child_tag == L"transfer") {
    stage_ = new StageTransfer(xml_child);
  } else if (xml_child_tag == L"interchunk") {
    stage_ = new StageInterchunk(xml_child);
  } else if (xml_child_tag == L"postchunk") {
    stage_ = new StagePostchunk(xml_child);
  } else {
    Error::Fatal(*xml_node, L"Transfer stage unknown (should be one of <transfer>, <interchunk>, <postchunk>).");
  }
}

void Root::PrintDebugInfo(const std::wstring& indentation) const {
  stage_->PrintDebugInfo(indentation);
}

Root::~Root() {
  if (stage_) {
    delete stage_;
  }
}
} // namespace xml2cpp
} // namespace apertium
