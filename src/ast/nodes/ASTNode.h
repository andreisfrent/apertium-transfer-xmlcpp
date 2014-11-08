#ifndef __APERTIUM_XML2CPP_AST_NODE_H
#define __APERTIUM_XML2CPP_AST_NODE_H

#include <string>
#include <unordered_map>

#include "../../parsing/XMLNode.h"

namespace apertium {
namespace xml2cpp {
class ASTNode {
 public:
  ASTNode();
  virtual ~ASTNode();

  virtual void Initialize(
      const std::unordered_map<std::wstring, std::wstring>& attrs);
  // TODO virtual void FillMetadata(...);
  // TODO virtual void Validate(..., metadata);
  // TODO virtual void GenerateCode(..., metadata);

  void set_line_no(int line_no);
  int get_line_no() const;
  void set_tag(const std::wstring& tag);
  const std::wstring& get_tag() const;
  void AddChild(ASTNode* child);

  static ASTNode *FromXMLNode(const XMLNode& xml_node);
  static ASTNode *UninitializedByTag(const std::wstring& tag);

 private:
  ASTNode(ASTNode&);
  ASTNode(ASTNode&&);
  ASTNode& operator=(ASTNode&);
  ASTNode& operator=(ASTNode&&);

 protected:
  int line_no_;
  std::wstring tag_;
  std::vector<ASTNode*> children_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
