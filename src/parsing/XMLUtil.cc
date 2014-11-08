#include "XMLUtil.h"

#include <codecvt>
#include <cstdlib>
#include <libxml/xmlreader.h>
#include <locale>
#include <string>

#include "XMLNode.h"

namespace apertium {
namespace xml2cpp {
std::wstring XMLUtil::GetCurrentElementName(xmlTextReaderPtr xml_reader_ptr) {
  xmlChar * xml_tag = xmlTextReaderName(xml_reader_ptr);
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt;
  std::wstring result = cvt.from_bytes((const char*) xml_tag);
  free(xml_tag);
  return result;
}

void XMLUtil::AddAttributesToXMLNode(xmlTextReaderPtr xml_reader_ptr, XMLNode *xml_node) {
  // TODO
}
} // namespace xml2cpp
} // namespace apertium
