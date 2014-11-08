include $(top_srcdir)/Makefile.common.mk

AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = apertium-xml2cpp
apertium_xml2cpp_SOURCES = \
  apertium-xml2cpp.cc \
  parsing/XMLUtil.cc \
  parsing/XMLTree.cc \
  parsing/XMLParser.cc \
  parsing/XMLNode.cc \
  ast/AST.cc \
  ast/nodes/ASTNode.cc \
  ast/nodes/ASTNode_Root.cc \
  ast/nodes/ASTNode_Undefined.cc \
  ast/nodes/ASTNode_Transfer.cc
