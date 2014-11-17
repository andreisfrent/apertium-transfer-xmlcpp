#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Macro::Macro(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  HandleXMLAttributes(xml_node);
  code_ = new CodeBlock(xml_node);
}

Macro::~Macro() {
  if (code_) delete code_;
}

void Macro::HandleXMLAttributes(const XMLNode *xml_node) {
  const auto& attrs = xml_node->get_attrs();

  if (attrs.find(L"n") == attrs.end()) {
    Error::Fatal(*xml_node, "Macro name is missing.");
  }
  if (attrs.find(L"npar") == attrs.end()) {
    Error::Fatal(*xml_node, "Parameter count attribute is mising on <def-macro>.");
  }

  name_ = attrs.find(L"n")->second;
  param_count_ = StringUtil::ConvertTo<int>(attrs.find(L"npar")->second);

  for (const auto& kv : attrs) {
    if (kv.first != L"n" && kv.first != L"npar") {
      Error::Warning(*xml_node, "Unknown attribute \"", kv.first, "\" on <def-macro>");
    }
  }
}

void Macro::PrintDebugInfo(const std::wstring& indentation) const {
  Error::Debug(indentation, "Macro ", name_, " of arity ", param_count_, ":");
}
} // namespace xml2cpp
} // namespace apertium
