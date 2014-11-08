#include "XMLParser.h"

#include <iostream>
#include <libxml/xmlreader.h>
#include <string>

#include "XMLUtil.h"
#include "XMLTree.h"
#include "XMLNode.h"

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

void XMLParser::Parse(XMLTree *tree) {
  // We assume the XML reader member is sane here.
  int ret = xmlTextReaderRead(xmlReader_);
  while (ret == 1) {
    int node_type = xmlTextReaderNodeType(xmlReader_);
    std::wstring tag = XMLUtil::GetCurrentElementName(xmlReader_);

    // We only deal with <> and </>.
    if (node_type == XML_READER_TYPE_ELEMENT ||
        node_type == XML_READER_TYPE_END_ELEMENT) {

      // On entry descend in the XML tree.
      if (node_type == XML_READER_TYPE_ELEMENT) {
        XMLNode *current_node = tree->Descend(tag);
        XMLUtil::AddAttributesToXMLNode(xmlReader_, current_node);
      }

      // On exit (or empty nodes) ascend in the XML tree.
      if (node_type == XML_READER_TYPE_END_ELEMENT ||
          xmlTextReaderIsEmptyElement(xmlReader_)) {
        tree->Ascend();
      }
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
