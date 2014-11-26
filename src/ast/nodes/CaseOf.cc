#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {

const std::wstring CaseOf::kSourceLanguage = L"sl";
const std::wstring CaseOf::kTargetLanguage = L"tl";

CaseOf::CaseOf(const XMLNode *xml_node) : RValue(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"pos", L"side", L"part"});
  pos_ = xml_node->GetMandatoryAttributeAs<int>(L"pos");
  side_ = xml_node->GetMandatoryAttribute(L"side");
  part_ = xml_node->GetMandatoryAttribute(L"part");

  Error::Assert(
    side_ == L"sl" || side_ == L"tl",
    *xml_node, "Invalid side attribute.");
}

void CaseOf::SemanticCheck(const CompilationContext *ctx) const {
}
} // namespace xml2cpp
} // namespace apertium
