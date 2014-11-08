#ifndef __APERTIUM_XML2CPP_XML_UTIL_H
#define __APERTIUM_XML2CPP_XML_UTIL_H

#include <libxml/xmlreader.h>
#include <string>

// Forward declaration.
namespace apertium {
namespace xml2cpp {
class XMLNode;
} // namespace xml2cpp
} // namespace apertium


namespace apertium {
namespace xml2cpp {
class XMLUtil {
 public:
  static std::wstring ConvertXMLCharToWString(const xmlChar *xml_str);
  static std::wstring GetCurrentElementName(xmlTextReaderPtr xml_reader_ptr);
  static void AddAttributesToXMLNode(xmlTextReaderPtr xml_reader_ptr, XMLNode *xml_node);
};
} // namespace xml2cpp
} // namespace apertium

#endif
