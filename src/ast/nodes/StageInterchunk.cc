#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
StageInterchunk::StageInterchunk(const XMLNode *xml_node)
    : Stage(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"c"});
}

StageInterchunk::~StageInterchunk() {
}
} // namespace xml2cpp
} // namespace apertium
