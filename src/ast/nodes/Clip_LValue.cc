#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Clip_LValue::Clip_LValue(const XMLNode *xml_node)
    : LValue(xml_node), ClipBase(xml_node) {
}
} // namespace xml2cpp
} // namespace apertium
