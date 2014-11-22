#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
const int ClipBase::kSourceLanguage = 0;
const int ClipBase::kTargetLanguage = 1;

const int ClipBase::kLemma = 0;
const int ClipBase::kLemmaHead = 1;
const int ClipBase::kLemmaQueue = 2;
const int ClipBase::kWhole = 3;

ClipBase::ClipBase(const XMLNode *xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"pos", L"side", L"part", L"queue", L"link-to", L"c"});
  pos_ = xml_node->GetMandatoryAttributeAs<int>(L"pos");
  side_ = StringToSide(xml_node, xml_node->GetMandatoryAttribute(L"side"));
  part_ = StringToPart(xml_node, xml_node->GetMandatoryAttribute(L"part"));
  queue_ = StringToQueue(xml_node, xml_node->GetOptionalAttribute(L"queue", L"yes"));
  link_to_ = xml_node->GetOptionalAttributeAs<int>(L"link_to_", L"-1");
}

int ClipBase::StringToSide(const XMLNode *xml_node, const std::wstring& side_str) {
  if (side_str == L"sl") {
    return kSourceLanguage;
  } else if (side_str == L"tl") {
    return kTargetLanguage;
  } else {
    Error::Fatal(*xml_node, "Invalid side attribute.");
  }

  // Avoid warnings from compiler.
  return -1;
}

int ClipBase::StringToPart(const XMLNode *xml_node, const std::wstring& part_str) {
  if (part_str == L"lem") {
    part_ = kLemma;
  } else if (part_str == L"lemh") {
    part_ = kLemmaHead;
  } else if (part_str == L"lemq") {
    part_ = kLemmaQueue;
  } else if (part_str == L"whole") {
    part_ = kWhole;
  } else {
    Error::Fatal(*xml_node, "Invalid part attribute.");
  }

  // Avoid warnings from compiler.
  return -1;
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
