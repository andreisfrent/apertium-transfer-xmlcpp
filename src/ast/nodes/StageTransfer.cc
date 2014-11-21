#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
StageTransfer::StageTransfer(const XMLNode *xml_node)
    : Stage(xml_node) {
  xml_node->EmitWarningOnUnknownAttributes({L"default", L"c"});
  std::wstring transfer_mode_str =
    xml_node->GetOptionalAttribute(L"default", L"lu");

  if (transfer_mode_str == L"lu") {
    transfer_mode_ = kLu;
  } else if (transfer_mode_str == L"chunk") {
    transfer_mode_ = kChunk;
  } else {
    Error::Fatal(*xml_node,
      "Unrecognized transfer mode \"", transfer_mode_str, "\".");
  }
}

StageTransfer::~StageTransfer() {
}

int StageTransfer::get_transfer_mode() const {
  return transfer_mode_;
}
} // namespace xml2cpp
} // namespace apertium
