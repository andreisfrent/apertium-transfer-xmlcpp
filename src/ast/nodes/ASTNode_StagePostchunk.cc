#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
StagePostchunk::StagePostchunk(const XMLNode *xml_node)
    : Stage(xml_node) {
  if (xml_node->get_attrs().size() != 0) {
    Error::Warning(*xml_node, "Extra attributes on <", xml_node->get_tag(), ">.");
  }
}

StagePostchunk::~StagePostchunk() {
}
} // namespace xml2cpp
} // namespace apertium
