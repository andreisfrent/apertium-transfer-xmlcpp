#include <apertium_xml2cpp.h>
#include <libxml/xmlreader.h>
#include <string>

namespace apertium {
namespace xml2cpp {
XMLParser::XMLParser(int fd) {
  xml_reader_ = xmlReaderForFd(fd, NULL, NULL, 0);
  if (xml_reader_ == NULL) {
    Error::Fatal(L"Could not initialize the XML parser.");
  }
}

XMLParser::XMLParser(char *filename) {
  xml_reader_ = xmlReaderForFile(filename, NULL, 0);
}

XMLParser::~XMLParser() {
  if (xml_reader_ != NULL) {
    xmlFreeTextReader(xml_reader_);
    xml_reader_ = NULL;
  }
}

void XMLParser::Parse(XMLTree *tree) {
  // We assume the XML reader member is sane here.
  int ret = xmlTextReaderRead(xml_reader_);
  while (ret == 1) {
    int node_type = xmlTextReaderNodeType(xml_reader_);
    std::wstring tag = XMLUtil::GetCurrentElementName(xml_reader_);

    // We only deal with <> and </>.
    if (node_type == XML_READER_TYPE_ELEMENT ||
        node_type == XML_READER_TYPE_END_ELEMENT) {

      // On entry descend in the XML tree.
      if (node_type == XML_READER_TYPE_ELEMENT) {
        XMLNode *current_node = tree->Descend(tag);
        XMLUtil::AddAttributesToXMLNode(xml_reader_, current_node);
        int line_no = XML_GET_LINE(xmlTextReaderCurrentNode(xml_reader_));
        current_node->set_line_no(line_no);
      }

      // On exit (or empty nodes) ascend in the XML tree.
      if (node_type == XML_READER_TYPE_END_ELEMENT ||
          xmlTextReaderIsEmptyElement(xml_reader_)) {
        tree->Ascend();
      }
    }

    // Advance to next node in XML stream.
    ret = xmlTextReaderRead(xml_reader_);
  }

  if (ret == -1) {
    Error::Fatal(L"Could not parse input as XML.");
  }
}
} // namespace xml2cpp
} // namespace apertium
