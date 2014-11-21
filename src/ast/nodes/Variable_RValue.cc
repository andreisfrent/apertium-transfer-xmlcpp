#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Variable_RValue::Variable_RValue(const XMLNode *xml_node)
    : RValue(xml_node), VariableBase(xml_node) {
}
} // namespace xml2cpp
} // namespace apertium
