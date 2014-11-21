#ifndef __APERTIUM_XML2CPP_AST_NODE_INTERCHUNK_H
#define __APERTIUM_XML2CPP_AST_NODE_INTERCHUNK_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Interchunk : public Stage {
 public:
  Interchunk(const XMLNode *xml_node);
  ~Interchunk();
};
} // namespace xml2cpp
} // namespace apertium

#endif
