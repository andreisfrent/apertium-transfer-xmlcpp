#ifndef __APERTIUM_XML2CPP_SYMBOLTABLE_H
#define __APERTIUM_XML2CPP_SYMBOLTABLE_H

#include <unordered_map>

namespace apertium {
namespace xml2cpp {
enum SymbolType {
  LitSymbol,
  VariableSymbol,
  MacroSymbol
};

class SymbolTable {
 public:
  SymbolTable();
  ~SymbolTable();

  static const std::wstring kNoSuchMapping;

  void RegisterSymbol(
      SymbolType symbol_type, const std::wstring& symbol_name);
  const std::wstring& GetMapping(
      SymbolType symbol_type, const std::wstring& symbol_name) const;
  bool HasSymbol(
      SymbolType symbol_type, const std::wstring& symbol_name) const;

 private:
  std::unordered_map<
      int,
      std::unordered_map<std::wstring, std::wstring>> mappings_;
  SymbolGenerator *symbol_generator_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
