#include "Error.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace apertium {
namespace xml2cpp {
void Error::Fatal(const std::wstring& description) {
   std::wcout << "\033[1;31mFATAL\033[0m " << description << std::endl;
   exit(-1);
}

void Error::Warning(const std::wstring& description) {
   std::wcout << "\033[1;33mWARNING\033[0m " << description << std::endl;
}
} // namespace xml2cpp
} // namespace apertium
