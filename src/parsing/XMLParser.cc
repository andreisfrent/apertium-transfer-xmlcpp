#include "XMLParser.h"

#include <codecvt>
#include <cstdlib>
#include <iostream>
#include <libxml/xmlreader.h>
#include <locale>
#include <string>

#include "ast-cls/ASTNode.h"

namespace apertium {
namespace xml2cpp {
XMLParser::XMLParser(int fd) {
  xmlReader_ = xmlReaderForFd(fd, NULL, NULL, 0);
  if (xmlReader_ == NULL) {
    FreeResources();
    throw std::wstring(L"Error! Could not initialize XML parser.");
  }
}

XMLParser::XMLParser(char *filename) {
  xmlReader_ = xmlReaderForFile(filename, NULL, 0);
}

void XMLParser::FreeResources() {
  if (xmlReader_ != NULL) {
    xmlFreeTextReader(xmlReader_);
    xmlReader_ = NULL;
  }
}

XMLParser::~XMLParser() {
  FreeResources();
}

std::wstring XMLParser::GetCurrentElementName() {
  xmlChar * xml_tag = xmlTextReaderName(xmlReader_);
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt;
  std::wstring result = cvt.from_bytes((const char*) xml_tag);
  free(xml_tag);
  return result;
}

void XMLParser::Parse() {
  // We assume the XML reader member is sane here.
  int ret = xmlTextReaderRead(xmlReader_);
  std::wstring indentation(L"");
  while (ret == 1) {
    int node_type = xmlTextReaderNodeType(xmlReader_);
    std::wstring tag = GetCurrentElementName();
    if (node_type == XML_READER_TYPE_ELEMENT) {
      std::wcout << indentation << L"+ " << tag << std::endl;
      indentation += L"  ";
      if (xmlTextReaderIsEmptyElement(xmlReader_)) {
        indentation = indentation.substr(0, indentation.size() - 2);
        std::wcout << indentation << L"- " << tag << std::endl;
      }
    }
    if (node_type == XML_READER_TYPE_END_ELEMENT) {
      indentation = indentation.substr(0, indentation.size() - 2);
      std::wcout << indentation << L"- " << tag << std::endl;
    }

    // Advance to next node in XML stream.
    ret = xmlTextReaderRead(xmlReader_);
  }

  if (ret == -1) {
    throw std::wstring(L"Error! Could not parse input as XML.");
  }
}
} // namespace xml2cpp
} // namespace apertium
