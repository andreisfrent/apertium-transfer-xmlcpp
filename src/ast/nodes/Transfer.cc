#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
const std::wstring Transfer::kLu(L"lu");
const std::wstring Transfer::kChunk(L"chunk");

Transfer::Transfer(const XMLNode *xml_node)
    : Stage(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"default", L"c"});
  transfer_mode_ = xml_node->GetOptionalAttribute(L"default", L"lu");

  Error::Assert(
      transfer_mode_ == kLu || transfer_mode_ == kChunk,
      *xml_node, "Unrecognized transfer mode \"", transfer_mode_, "\".");
}
} // namespace xml2cpp
} // namespace apertium
