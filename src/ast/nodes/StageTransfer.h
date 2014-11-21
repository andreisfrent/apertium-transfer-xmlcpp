#ifndef __APERTIUM_XML2CPP_AST_NODE_STAGETRANSFER_H
#define __APERTIUM_XML2CPP_AST_NODE_STAGETRANSFER_H

#include <apertium_xml2cpp.h>

namespace apertium {
namespace xml2cpp {
class StageTransfer : public Stage {
 public:
  StageTransfer(const XMLNode *xml_node);
  ~StageTransfer();

  const int kLu = 0;
  const int kChunk = 1;

  int get_transfer_mode() const;

 private:
  int transfer_mode_;
};
} // namespace xml2cpp
} // namespace apertium

#endif
