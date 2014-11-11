#ifndef __APERTIUM_XML2CPP_STRINGUTIL_H
#define __APERTIUM_XML2CPP_STRINGUTIL_H

#include <sstream>
#include <string>

namespace apertium {
namespace xml2cpp {
class StringUtil {
 public:
  template<typename T>
  static T ConvertTo(const std::wstring& s) {
    T result;
    std::wstringstream wss;
    wss << s;
    wss >> result;
    return result;
  }
};
} // namespace xml2cpp
} // namespace apertium

#endif
