#ifndef __APERTIUM_XML2CPP_ERROR_H
#define __APERTIUM_XML2CPP_ERROR_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "../parsing/XMLNode.h"
#include "../ast/nodes/ASTNode.h"

namespace apertium {
namespace xml2cpp {
class Error {
 private:
  template<typename T>
  static void _Out(const T& t) {
    std::wcerr << t << std::endl;
  }

  template<typename T, typename ... TArgs>
  static void _Out(const T& t, const TArgs& ... t_args) {
    std::wcerr << t;
    _Out(t_args...);
  }

 public:
  template<typename ... TArgs>
  static void Fatal(const TArgs& ... t_args) {
     std::wcerr << "\033[1;31mFATAL\033[0m ";
     _Out(t_args...);
     exit(-1);
  }

  template<typename ... TArgs>
  static void Warning(const TArgs& ... t_args) {
     std::wcerr << "\033[1;33mWARNING\033[0m ";
     _Out(t_args...);
  }

  template<typename ... TArgs>
  static void Info(const TArgs& ... t_args) {
     std::wcerr << "\033[1;32mINFO\033[0m ";
     _Out(t_args...);
  }

  template<typename ... TArgs>
  static void Debug(const TArgs& ... t_args) {
     std::wcerr << "\033[1;34mDEBUG\033[0m ";
     _Out(t_args...);
  }

  static void Unimplemented(const std::string& method_name);
};
} // namespace xml2cpp
} // namespace apertium

#endif
