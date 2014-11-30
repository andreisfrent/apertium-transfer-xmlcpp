#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
AST::AST(const XMLTree& xml_tree) {
  const XMLNode *xml_root = xml_tree.get_root();
  Error::Assert(
      xml_root->get_children().size() == 1,
      xml_root, L"XML root node has more than one child.");
  const XMLNode *xml_stage_node = xml_root->get_children().at(0);
  stage_ = Stage::FromXMLNode(xml_stage_node);
}

AST::~AST() {
  delete stage_;
}

void AST::PrintDebugInfo() const {
  stage_->PrintDebugInfo();
}

void AST::SemanticCheck(const CompilationContext *ctx) const {
  stage_->SemanticCheck(ctx);
}

const Stage *AST::get_root() const {
  return stage_;
}

void AST::GenerateCode(CompilationContext *ctx) const {
  stage_->GenerateCode(ctx);
}
} // namespace apertium
} // namespace xml2cpp
