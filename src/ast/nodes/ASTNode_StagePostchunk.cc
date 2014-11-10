#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_StagePostchunk::ASTNode_StagePostchunk(const XMLNode *xml_node)
    : ASTNode_Stage(xml_node) {
  if (xml_node->get_attrs().size() != 0) {
    Error::Warning("Extra attributes on <", xml_node->get_tag(), ">.");
  }
}

ASTNode_StagePostchunk::~ASTNode_StagePostchunk() {
}
} // namespace xml2cpp
} // namespace apertium
