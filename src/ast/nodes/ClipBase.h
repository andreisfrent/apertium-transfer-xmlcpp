#ifndef __APERTIUM_XML2CPP_CLIP_BASE_H
#define __APERTIUM_XML2CPP_CLIP_BASE_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class ClipBase {
 public:
  ClipBase(const XMLNode *xml_node);

  static const std::wstring kSourceLanguage;
  static const std::wstring kTargetLanguage;

 protected:
  int pos_;
  std::wstring side_;
  std::wstring part_;
  bool queue_;
  int link_to_;

  bool StringToQueue(const XMLNode *xml_node, const std::wstring& queue_str);
};
} // namespace xml2cpp
} // namespace apertium

#endif

