#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Clip_RValue::Clip_RValue(const XMLNode *xml_node)
    : RValue(xml_node), ClipBase(xml_node) {
}
} // namespace xml2cpp
} // namespace apertium
