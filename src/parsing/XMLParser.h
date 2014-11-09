#ifndef __APERTIUM_XML2CPP_XML_PARSER_H
#define __APERTIUM_XML2CPP_XML_PARSER_H

#include <libxml/xmlreader.h>
#include <string>

// Forward declaration.
namespace apertium {
namespace xml2cpp {
class XMLTree;
} // namespace xml2cpp
} // namespace apertium

namespace apertium {
namespace xml2cpp {
class XMLParser {
 public:
  /// Construct the builder from a file descriptor (to be used whenever the XML
  /// is fed to stdin).
  explicit XMLParser(int fd);

  /// Construct the builder from a file.
  explicit XMLParser(char *filename);

  /// Destructor.
  ~XMLParser();

  /// Build an XMLTree from the input.
  void Parse(XMLTree *xml_tree);

 private:
  std::wstring GetCurrentElementName();

  xmlTextReaderPtr xml_reader_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
