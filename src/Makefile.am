include $(top_srcdir)/Makefile.common.mk

AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = apertium-xml2cpp
apertium_xml2cpp_SOURCES = \
  apertium-xml2cpp.cc \
  misc/StringUtil.cc \
  parsing/XMLUtil.cc \
  parsing/XMLTree.cc \
  parsing/XMLParser.cc \
  parsing/XMLNode.cc \
  ast/nodes/ASTNode.cc \
  ast/nodes/ASTNode_Root.cc \
  ast/nodes/ASTNode_Stage.cc \
  ast/nodes/ASTNode_StageInterchunk.cc \
  ast/nodes/ASTNode_StagePostchunk.cc \
  ast/nodes/ASTNode_StageTransfer.cc \
  ast/nodes/ASTNode_GlobalVariables.cc \
  ast/nodes/ASTNode_GlobalLists.cc \
  ast/nodes/ASTNode_GlobalMacros.cc \
  ast/nodes/ASTNode_Categories.cc \
  ast/nodes/ASTNode_Attributes.cc \
  ast/nodes/ASTNode_Macro.cc \
  ast/nodes/ASTNode_CodeBlock.cc \
  ast/AST.cc \
  error/Error.cc
