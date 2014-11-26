#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
GetCaseFrom::GetCaseFrom(const XMLNode *xml_node) : RValue(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"pos"});
  pos_ = xml_node->GetMandatoryAttributeAs<int>(L"pos");

  Error::Assert(
      xml_node->get_children().size() == 1,
      *xml_node, "Should have exactly one child.");

  value_ = RValue::FromXMLNode(xml_node->get_children().at(0));
}

GetCaseFrom::~GetCaseFrom() {
  delete value_;
}

void GetCaseFrom::SemanticCheck(const CompilationContext *ctx) const {
  value_->SemanticCheck(ctx);
}
} // namespace xml2cpp
} // namespace apertium
