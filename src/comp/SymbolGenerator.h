#ifndef __APERTIUM_XML2CPP_SYMBOLGENERATOR_H
#define __APERTIUM_XML2CPP_SYMBOLGENERATOR_H

#include <string>

namespace apertium {
namespace xml2cpp {
class SymbolGenerator {
 public:
  SymbolGenerator(const std::wstring& prefix);
  std::wstring Next();

 private:
  static const int kCounterLimit;

  std::wstring prefix_;
  int counter_;
};
} // namespace apertium
} // namespace xml2cpp

#endif
