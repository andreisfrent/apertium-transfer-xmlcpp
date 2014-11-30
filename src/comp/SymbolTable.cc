#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
const std::wstring SymbolTable::kNoSuchMapping;

SymbolTable::SymbolTable() {
  symbol_generator_ = new SymbolGenerator(L"sym");
}

SymbolTable::~SymbolTable() {
  delete symbol_generator_;
}

const std::wstring& SymbolTable::RegisterSymbol(
      const std::wstring& symbol_type, const std::wstring& symbol_name) {
  if (HasSymbol(symbol_type, symbol_name)) {
    // TODO Add more info.
    Error::Fatal("Symbol already registered.");
  }

  mappings_[symbol_type][symbol_name] = symbol_generator_->Next();
  return GetMapping(symbol_type, symbol_name);
}

const std::wstring& SymbolTable::GetMapping(
    const std::wstring& symbol_type, const std::wstring& symbol_name) const {
  if (HasSymbol(symbol_type, symbol_name)) {
    const auto& type_specific_mapping_it = mappings_.find(symbol_type);
    const auto& symbol_mapping_it =
        type_specific_mapping_it->second.find(symbol_name);
    return symbol_mapping_it->second;
  }

  // TODO Add more info.
  Error::Fatal("Symbol table lookup failed.");
  return kNoSuchMapping;
}

bool SymbolTable::HasSymbol(
    const std::wstring& symbol_type, const std::wstring& symbol_name) const {
  const auto& type_specific_mapping_it = mappings_.find(symbol_type);
  if (type_specific_mapping_it == mappings_.end()) {
    return false;
  }

  const auto& symbol_mapping_it =
      type_specific_mapping_it->second.find(symbol_name);
  if (symbol_mapping_it == type_specific_mapping_it->second.end()) {
    return false;
  }

  return true;
}
} // namespace apertium
} // namespace xml2cpp
