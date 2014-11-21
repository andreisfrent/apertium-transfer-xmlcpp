#ifndef __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H
#define __APERTIUM_XML2CPP_AST_NODE_TRANSFER_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class Transfer : public Stage {
 public:
  Transfer(const XMLNode *xml_node);
  ~Transfer();

  const int kLu = 0;
  const int kChunk = 1;

  int get_transfer_mode() const;

 private:
  int transfer_mode_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
