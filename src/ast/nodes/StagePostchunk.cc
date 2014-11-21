#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
StagePostchunk::StagePostchunk(const XMLNode *xml_node)
    : Stage(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"c"});
}

StagePostchunk::~StagePostchunk() {
}
} // namespace xml2cpp
} // namespace apertium
