#include <apertium_xml2cpp.h>

#include <string>
#include <sstream>
#include <iomanip>

namespace apertium {
namespace xml2cpp {
const int SymbolGenerator::kCounterLimit = 99999;

SymbolGenerator::SymbolGenerator(const std::wstring& prefix)
    : prefix_(prefix), counter_(0) {
}

std::wstring SymbolGenerator::Next() {
  Error::Assert(counter_ < kCounterLimit,
      "Symbol count for prefix \"", prefix_, "\" exceeded maximum value of ",
      kCounterLimit, ".");
  std::wostringstream wss;
  wss << prefix_ << L"_" << std::setw(4) << std::setfill(L'0') << counter_;
  ++counter_;
  return wss.str();
}
} // namespace apertium
} // namespace xml2cpp
