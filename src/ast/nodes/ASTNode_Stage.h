#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGE_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ASTNode_Stage : public ASTNode {
 public:
  ASTNode_Stage(const XMLNode *xml_node);
  virtual ~ASTNode_Stage();

  virtual void PrintDebugInfo(const std::wstring& indentation = L"") const override;

 private:
  void SetSectionPointersToNull();
  void HandleXMLChild_section_def_vars(const XMLNode *xml_child);
  void HandleXMLChild_section_def_lists(const XMLNode *xml_child);
  void HandleXMLChild_section_def_cats(const XMLNode *xml_child);
  void FillWithEmptySections();
  void CheckMandatorySections() const;

 protected:
  ASTNode_GlobalVariables *global_variables_;
  ASTNode_GlobalLists *global_lists_;
  ASTNode_Categories *lexical_categories_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
