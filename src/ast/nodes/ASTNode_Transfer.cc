#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_Transfer::ASTNode_Transfer(const XMLNode *xml_node)
    : ASTNode_Stage(xml_node) {
}

ASTNode_Transfer::~ASTNode_Transfer() {
}
} // namespace xml2cpp
} // namespace apertium
