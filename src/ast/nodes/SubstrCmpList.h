#ifndef __APERTIUM_XML2CPP_SUBSTRCMPLIST_H
#define __APERTIUM_XML2CPP_SUBSTRCMPLIST_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class SubstrCmpList : public Condition {
 public:
  SubstrCmpList(const XMLNode *xml_node);
  ~SubstrCmpList();

  static const int kBegin;
  static const int kEnd;
  static const int kExact;

 private:
  void HandleXMLTag(const XMLNode *xml_node);
  void HandleXMLChildren(const XMLNode *xml_node);
  void HandleXMLAttributes(const XMLNode *xml_node);
  void HandleListReference(const XMLNode *xml_node);

  RValue *substr_;
  std::wstring list_;
  bool caseless_;
  int where_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
