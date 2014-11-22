#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
Chunk::Chunk(const XMLNode *xml_node)
    : RValue(xml_node) {
  Error::Assert(
      xml_node->get_children().size() >= 2,
      *xml_node, "Element should have at least two children.");

  ExtractTags(xml_node);
  ExtractValues(xml_node);
}

Chunk::~Chunk() {
  for (RValue *rvalue : tags_) {
    delete rvalue;
  }
  for (RValue *rvalue : values_) {
    delete rvalue;
  }
}

void Chunk::ExtractTags(const XMLNode *xml_node) {
  Error::Assert(
    xml_node->get_children().at(0)->get_tag() == L"tags",
    *xml_node, "First chhild should be <tags>");

  const XMLNode *tags_node = xml_node->get_children().at(0);
  for (const XMLNode *tag_node : tags_node->get_children()) {
    Error::Assert(
        tag_node->get_tag() == L"tag",
        *tag_node, "Should be <tag>.");
    Error::Assert(
        tag_node->get_children().size() == 1,
        *tag_node, "Should have exactly one child.");
    RValue *tag_value = RValue::FromXMLNode(tag_node->get_children().at(0));
    tags_.push_back(tag_value);
  }
}

void Chunk::ExtractValues(const XMLNode *xml_node) {
  for (auto it = xml_node->get_children().begin() + 1;
      it != xml_node->get_children().end(); ++it) {
    RValue *value = RValue::FromXMLNode(*it);
    values_.push_back(value);
  }
}
} // namespace xml2cpp
} // namespace apertium
