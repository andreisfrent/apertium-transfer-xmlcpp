#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
StageTransfer::StageTransfer(const XMLNode *xml_node)
    : Stage(xml_node) {
  SetDefaultAttrs();
  HandleXMLAttrs(xml_node);
}

StageTransfer::~StageTransfer() {
}

void StageTransfer::HandleXMLAttrs(const XMLNode *xml_node) {
  for (const auto& kv : xml_node->get_attrs()) {
    if (kv.first == L"default") {
      HandleXMLAttr_default(kv.second);
    } else {
      Error::Warning(*xml_node, "Ignoring attribute \"", kv.first, "\".");
    }
  }
}

void StageTransfer::SetDefaultAttrs() {
  transfer_mode_ = kLu;
}

void StageTransfer::HandleXMLAttr_default(const std::wstring& value) {
  if (value == L"lu") {
    transfer_mode_ = kLu;
  } else if (value == L"chunk") {
    transfer_mode_ = kChunk;
  } else {
    Error::Fatal(*this, "Unrecognized transfer mode \"", value, "\".");
  }
}

int StageTransfer::get_transfer_mode() const {
  return transfer_mode_;
}
} // namespace xml2cpp
} // namespace apertium
