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

  /// This method is directly called by the destructor and frees any used
  /// resources. Its main purpose is to be able to free resources when throwing
  /// an exception from the constructor.
  void FreeResources();

 private:
  XMLParser(XMLParser&);
  XMLParser(XMLParser&&);
  XMLParser& operator=(XMLParser&);
  XMLParser& operator=(XMLParser&&);

  std::wstring GetCurrentElementName();

  xmlTextReaderPtr xml_reader_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
