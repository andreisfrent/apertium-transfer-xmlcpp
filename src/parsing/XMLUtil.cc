#include "XMLUtil.h"

#include <codecvt>
#include <cstdlib>
#include <iostream>
#include <libxml/xmlreader.h>
#include <locale>
#include <string>

#include "XMLNode.h"

namespace apertium {
namespace xml2cpp {
std::wstring XMLUtil::ConvertXMLCharToWString(const xmlChar *xml_str) {
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt;
  std::wstring result = cvt.from_bytes((const char*) xml_str);
  return result;
}

std::wstring XMLUtil::GetCurrentElementName(xmlTextReaderPtr xml_reader_ptr) {
  xmlChar * xml_tag = xmlTextReaderName(xml_reader_ptr);
  std::wstring result = ConvertXMLCharToWString(xml_tag);
  free(xml_tag);
  return result;
}

void XMLUtil::AddAttributesToXMLNode(xmlTextReaderPtr xml_reader_ptr, XMLNode *xml_node) {
  xmlNodePtr raw_node = xmlTextReaderCurrentNode(xml_reader_ptr);
  for(xmlAttrPtr attr = raw_node->properties; attr != NULL; attr = attr->next) {
    std::wstring attr_name = ConvertXMLCharToWString(attr->name);
    xmlChar *raw_attr_value = xmlTextReaderGetAttribute(xml_reader_ptr, attr->name);
    std::wstring attr_value = ConvertXMLCharToWString(raw_attr_value);
    free(raw_attr_value);
    std::wcout << attr_name << L" -> " << attr_value << std::endl;
  }
}
} // namespace xml2cpp
} // namespace apertium
