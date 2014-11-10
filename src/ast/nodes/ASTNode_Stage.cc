#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
ASTNode_Stage::ASTNode_Stage(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  SetSectionPointersToNull();

  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"section-def-vars") {
      HandleXMLChild_section_def_vars(xml_child);
    } else if (xml_child->get_tag() == L"section-def-lists") {
      HandleXMLChild_section_def_lists(xml_child);
    } else if (xml_child->get_tag() == L"section-def-cats") {
      HandleXMLChild_section_def_cats(xml_child);
    } else {
      Error::Warning("Unrecognized section <", xml_child->get_tag(), ">.");
    }
  }

  CheckMandatorySections();
  FillWithEmptySections();
}

void ASTNode_Stage::PrintDebugInfo(const std::wstring& indentation) const {
  global_variables_->PrintDebugInfo(indentation);
  global_lists_->PrintDebugInfo(indentation);
  lexical_categories_->PrintDebugInfo(indentation);
}

ASTNode_Stage::~ASTNode_Stage() {
  if (global_variables_) delete global_variables_;
  if (global_lists_) delete global_lists_;
  if (lexical_categories_) delete lexical_categories_;
}

void ASTNode_Stage::HandleXMLChild_section_def_lists(const XMLNode *xml_child) {
  if (global_lists_ == NULL) {
    global_lists_ = new ASTNode_GlobalLists(xml_child);
  } else {
    Error::Fatal("Multiple <section-def-lists> detected.");
  }
}

void ASTNode_Stage::HandleXMLChild_section_def_vars(const XMLNode *xml_child) {
  if (global_variables_ == NULL) {
    global_variables_ = new ASTNode_GlobalVariables(xml_child);
  } else {
    Error::Fatal("Multiple <section-def-vars> detected.");
  }
}

void ASTNode_Stage::HandleXMLChild_section_def_cats(const XMLNode *xml_child) {
  if (lexical_categories_ == NULL) {
    lexical_categories_ = new ASTNode_Categories(xml_child);
  } else {
    Error::Fatal("Multiple <section-def-cats> detected.");
  }
}

void ASTNode_Stage::FillWithEmptySections() {
  if (!global_variables_) global_variables_ = new ASTNode_GlobalVariables();
  if (!global_lists_) global_lists_ = new ASTNode_GlobalLists();
}

void ASTNode_Stage::CheckMandatorySections() const {
  if (!lexical_categories_) Error::Fatal("Mandatory <section-def-cats> missing.");
}

void ASTNode_Stage::SetSectionPointersToNull() {
  global_variables_ = NULL;
  global_lists_ = NULL;
  lexical_categories_ = NULL;
}
} // namespace xml2cpp
} // namespace apertium
