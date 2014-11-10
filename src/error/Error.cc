#include <apertium_xml2cpp.h>
#include <string>
#include <iostream>

namespace apertium {
namespace xml2cpp {
void Error::Unimplemented(const std::string& method_name) {
  std::cout << "\033[1;36mUNIMPLEMENTED\033[0m " << method_name << "." << std::endl;
}
} // namespace xml2cpp
} // namespace apertium
