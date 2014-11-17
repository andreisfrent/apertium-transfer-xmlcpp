#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGE_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Stage : public ASTNode {
 public:
  Stage(const XMLNode *xml_node);
  virtual ~Stage();

  virtual void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  void SetSectionPointersToNull();
  void HandleXMLChild_section_def_vars(const XMLNode *xml_child);
  void HandleXMLChild_section_def_lists(const XMLNode *xml_child);
  void HandleXMLChild_section_def_cats(const XMLNode *xml_child);
  void HandleXMLChild_section_def_attrs(const XMLNode *xml_child);
  void HandleXMLChild_section_def_macros(const XMLNode *xml_child);
  void HandleXMLChild_section_rules(const XMLNode *xml_child);
  void FillWithEmptySections();
  void CheckMandatorySections() const;

 protected:
  GlobalVariables *global_variables_;
  GlobalLists *global_lists_;
  GlobalMacros *global_macros_;
  Categories *lexical_categories_;
  Attributes *attributes_;
  Rules *rules_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
