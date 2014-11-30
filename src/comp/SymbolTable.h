#ifndef __APERTIUM_XML2CPP_SYMBOLTABLE_H
#define __APERTIUM_XML2CPP_SYMBOLTABLE_H

#include <unordered_map>
#include <string>

namespace apertium {
namespace xml2cpp {
class SymbolGenerator;
class SymbolTable {
 public:
  SymbolTable();
  ~SymbolTable();

  static const std::wstring kNoSuchMapping;

  const std::wstring& RegisterSymbol(
      const std::wstring& symbol_type, const std::wstring& symbol_name);
  const std::wstring& GetMapping(
      const std::wstring& symbol_type, const std::wstring& symbol_name) const;
  bool HasSymbol(
      const std::wstring& symbol_type, const std::wstring& symbol_name) const;

 private:
  std::unordered_map<
      std::wstring,
      std::unordered_map<std::wstring, std::wstring>> mappings_;
  SymbolGenerator *symbol_generator_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
