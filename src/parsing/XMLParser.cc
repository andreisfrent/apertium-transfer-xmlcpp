#include "XMLParser.h"

#include <iostream>
#include <libxml/xmlreader.h>
#include <string>

#include "XMLUtil.h"

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

void XMLParser::Parse() {
  // We assume the XML reader member is sane here.
  int ret = xmlTextReaderRead(xmlReader_);
  std::wstring indentation(L"");
  while (ret == 1) {
    int node_type = xmlTextReaderNodeType(xmlReader_);
    std::wstring tag = XMLUtil::GetCurrentElementName(xmlReader_);
    if (node_type == XML_READER_TYPE_ELEMENT) {
      XMLUtil::AddAttributesToXMLNode(xmlReader_, NULL);
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
