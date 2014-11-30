#ifndef __APERTIUM_XML2CPP_STAGE_H
#define __APERTIUM_XML2CPP_STAGE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Stage : public ASTNode {
 public:
  virtual ~Stage();

  virtual void PrintDebugInfo(const std::wstring& indentation = L"") const override;

  static Stage *FromXMLNode(const XMLNode *xml_node);

  const GlobalVariables *get_global_variables() const;
  const GlobalLists *get_global_lists() const;
  const GlobalMacros *get_global_macros() const;

  void SemanticCheck(const CompilationContext *ctx) const override;

  // TODO should be pure virtual.
  virtual void GenerateCode(CompilationContext *ctx);

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
  Stage(const XMLNode *xml_node);

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
