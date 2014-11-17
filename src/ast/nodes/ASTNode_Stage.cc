#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Stage::Stage(const XMLNode *xml_node)
    : ASTNode(xml_node) {
  SetSectionPointersToNull();

  for (const XMLNode *xml_child : xml_node->get_children()) {
    if (xml_child->get_tag() == L"section-def-vars") {
      HandleXMLChild_section_def_vars(xml_child);
    } else if (xml_child->get_tag() == L"section-def-lists") {
      HandleXMLChild_section_def_lists(xml_child);
    } else if (xml_child->get_tag() == L"section-def-cats") {
      HandleXMLChild_section_def_cats(xml_child);
    } else if (xml_child->get_tag() == L"section-def-attrs") {
      HandleXMLChild_section_def_attrs(xml_child);
    } else if (xml_child->get_tag() == L"section-def-macros") {
      HandleXMLChild_section_def_macros(xml_child);
    } else if (xml_child->get_tag() == L"section-rules") {
      HandleXMLChild_section_rules(xml_child);
    } else {
      Error::Warning(*xml_node, "Unrecognized section <", xml_child->get_tag(), ">.");
    }
  }

  CheckMandatorySections();
  FillWithEmptySections();
}

void Stage::PrintDebugInfo(const std::wstring& indentation) const {
  global_variables_->PrintDebugInfo(indentation);
  global_lists_->PrintDebugInfo(indentation);
  global_macros_->PrintDebugInfo(indentation);
  lexical_categories_->PrintDebugInfo(indentation);
  attributes_->PrintDebugInfo(indentation);
  rules_->PrintDebugInfo(indentation);
}

Stage::~Stage() {
  if (global_variables_) delete global_variables_;
  if (global_lists_) delete global_lists_;
  if (global_macros_) delete global_macros_;
  if (lexical_categories_) delete lexical_categories_;
  if (attributes_) delete attributes_;
  if (rules_) delete rules_;
}

void Stage::HandleXMLChild_section_def_lists(const XMLNode *xml_child) {
  if (global_lists_ == NULL) {
    global_lists_ = new GlobalLists(xml_child);
  } else {
    Error::Fatal(*xml_child, "Multiple <section-def-lists> detected.");
  }
}

void Stage::HandleXMLChild_section_def_vars(const XMLNode *xml_child) {
  if (global_variables_ == NULL) {
    global_variables_ = new GlobalVariables(xml_child);
  } else {
    Error::Fatal(*xml_child, "Multiple <section-def-vars> detected.");
  }
}

void Stage::HandleXMLChild_section_def_macros(const XMLNode *xml_child) {
  if (global_macros_ == NULL) {
    global_macros_ = new GlobalMacros(xml_child);
  } else {
    Error::Fatal(*xml_child, "Multiple <section-def-macros> detected.");
  }
}

void Stage::HandleXMLChild_section_def_cats(const XMLNode *xml_child) {
  if (lexical_categories_ == NULL) {
    lexical_categories_ = new Categories(xml_child);
  } else {
    Error::Fatal(*xml_child, "Multiple <section-def-cats> detected.");
  }
}

void Stage::HandleXMLChild_section_def_attrs(const XMLNode *xml_child) {
  if (attributes_ == NULL) {
    attributes_ = new Attributes(xml_child);
  } else {
    Error::Fatal(*xml_child, "Multiple <section-def-attrs> detected.");
  }
}

void Stage::HandleXMLChild_section_rules(const XMLNode *xml_child) {
  if (rules_ == NULL) {
    rules_ = new Rules(xml_child);
  } else {
    Error::Fatal(*xml_child, "Multiple <section-rules> detected.");
  }
}

void Stage::FillWithEmptySections() {
  if (!global_variables_) global_variables_ = new GlobalVariables();
  if (!global_lists_) global_lists_ = new GlobalLists();
  if (!global_macros_) global_macros_ = new GlobalMacros();
}

void Stage::CheckMandatorySections() const {
  if (!lexical_categories_) Error::Fatal(*this, "Mandatory <section-def-cats> missing.");
  if (!attributes_) Error::Fatal(*this, "Mandatory <section-def-attrs> missing.");
  if (!rules_) Error::Fatal(*this, "Mandatory <section-rules> missing.");
}

void Stage::SetSectionPointersToNull() {
  global_variables_ = NULL;
  global_lists_ = NULL;
  global_macros_ = NULL;
  lexical_categories_ = NULL;
  attributes_ = NULL;
  rules_ = NULL;
}
} // namespace xml2cpp
} // namespace apertium
