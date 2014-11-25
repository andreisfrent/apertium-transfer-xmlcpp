#ifndef __APERTIUM_XML2CPP_CHOOSE_H
#define __APERTIUM_XML2CPP_CHOOSE_H

#include <apertium_xml2cpp.h>

#include <vector>
#include <utility>

namespace apertium {
namespace xml2cpp {
class Choose : public Statement {
 public:
  Choose(const XMLNode *xml_node);
  ~Choose();

 private:
  std::vector<std::pair<Condition*, CodeBlock*>> cases_;
  CodeBlock *otherwise_;

  void HandleXMLWhen(const XMLNode *xml_node);
  Condition *HandleXMLTest(const XMLNode *xml_node);
  void ExtractSingleOtherwise(const XMLNode *xml_node);
  void ExtractMultipleWhen(const XMLNode *xml_node);
  void SemanticCheck(const CompilationContext *ctx) const override;
};
} // namespace xml2cpp
} // namespace apertium

#endif
