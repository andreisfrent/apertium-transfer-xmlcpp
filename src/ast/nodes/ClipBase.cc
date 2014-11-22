#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
const std::wstring ClipBase::kSourceLanguage = L"sl";
const std::wstring ClipBase::kTargetLanguage = L"tl";

ClipBase::ClipBase(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"pos", L"side", L"part", L"queue", L"link-to", L"c"});
  pos_ = xml_node->GetMandatoryAttributeAs<int>(L"pos");
  side_ = xml_node->GetMandatoryAttribute(L"side");
  part_ = xml_node->GetMandatoryAttribute(L"part");
  queue_ = StringToQueue(xml_node, xml_node->GetOptionalAttribute(L"queue", L"yes"));
  link_to_ = xml_node->GetOptionalAttributeAs<int>(L"link_to_", L"-1");

  Error::Assert(
    side_ == L"sl" || side_ == L"tl",
    *xml_node, "Invalid side attribute.");
}

bool ClipBase::StringToQueue(const XMLNode *xml_node, const std::wstring& queue_str) {
  if (queue_str == L"yes") {
    return true;
  } else if (queue_str == L"no") {
    return false;
  } else {
    Error::Fatal(*xml_node, "Invalid queue attribute.");
  }

  // Avoid warnings from compiler.
  return false;
}
} // namespace xml2cpp
} // namespace apertium
