#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_StageInterchunk::ASTNode_StageInterchunk(const XMLNode *xml_node)
    : ASTNode_Stage(xml_node) {
  if (xml_node->get_attrs().size() != 0) {
    Error::Warning(*xml_node, "Extra attributes on <", xml_node->get_tag(), ">.");
  }
}

ASTNode_StageInterchunk::~ASTNode_StageInterchunk() {
}
} // namespace xml2cpp
} // namespace apertium
