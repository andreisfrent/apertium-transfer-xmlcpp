#ifndef __APERTIUM_XML2CPP_ERROR_H
#define __APERTIUM_XML2CPP_ERROR_H

#include <cstdlib>
#include <iostream>
#include <string>

namespace apertium {
namespace xml2cpp {
class Error {
 private:
  template<typename T>
  static void _Out(const T& t) {
    std::wcout << t << std::endl;
  }

  template<typename T, typename ... TArgs>
  static void _Out(const T& t, TArgs ... t_args) {
    std::wcout << t;
    _Out(t_args...);
  }

 public:
  template<typename ... TArgs>
  static void Fatal(TArgs ... t_args) {
     std::wcout << "\033[1;31mFATAL\033[0m ";
     _Out(t_args...);
     exit(-1);
  }

  template<typename ... TArgs>
  static void Warning(TArgs ... t_args) {
     std::wcout << "\033[1;33mWARNING\033[0m ";
     _Out(t_args...);
  }
};
} // namespace xml2cpp
} // namespace apertium

#endif
