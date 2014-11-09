#ifndef __APERTIUM_XML2CPP_ERROR_H
#define __APERTIUM_XML2CPP_ERROR_H

#include <string>

namespace apertium {
namespace xml2cpp {
class Error {
 public:
  static void Fatal(const std::wstring& description);
  static void Warning(const std::wstring& description);
};
} // namespace xml2cpp
} // namespace apertium

#endif
