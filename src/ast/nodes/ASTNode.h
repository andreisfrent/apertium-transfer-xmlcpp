#ifndef __APERTIUM_XML2CPP_AST_NODE_H
#define __APERTIUM_XML2CPP_AST_NODE_H

#include <apertium_xml2cpp.h>
#include <string>

namespace apertium {
namespace xml2cpp {
class ASTNode {
 public:
  ASTNode();
  explicit ASTNode(const XMLNode *xml_node);
  virtual ~ASTNode();

  // TODO virtual void FillMetadata(...);
  // TODO virtual void Validate(..., metadata);
  // TODO virtual void GenerateCode(..., metadata);

  void set_line_no(int line_no);
  int get_line_no() const;
  void set_tag(const std::wstring& tag);
  const std::wstring& get_tag() const;
  virtual void PrintDebugInfo(const std::wstring& indentation = L"") const;

 protected:
  int line_no_;
  std::wstring tag_;
};
} // namespace xml2cpp
} // namespace apertium

std::wostream& operator <<(std::wostream& stream, const apertium::xml2cpp::ASTNode& ast_node);
#endif
