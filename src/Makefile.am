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
	ast/nodes/ASTNode_Action.cc \
	ast/nodes/ASTNode_AttrItem.cc \
	ast/nodes/ASTNode_CatItem.cc \
	ast/nodes/ASTNode_Clip.cc \
	ast/nodes/ASTNode_DefAttr.cc \
	ast/nodes/ASTNode_DefCat.cc \
	ast/nodes/ASTNode_DefVar.cc \
	ast/nodes/ASTNode_Let.cc \
	ast/nodes/ASTNode_LitTag.cc \
	ast/nodes/ASTNode_Lu.cc \
	ast/nodes/ASTNode_Out.cc \
	ast/nodes/ASTNode_Pattern.cc \
	ast/nodes/ASTNode_PatternItem.cc \
	ast/nodes/ASTNode_Rule.cc \
	ast/nodes/ASTNode_SectionDefAttrs.cc \
	ast/nodes/ASTNode_SectionDefCats.cc \
	ast/nodes/ASTNode_SectionDefVars.cc \
	ast/nodes/ASTNode_SectionRules.cc \
  ast/nodes/ASTNode_Root.cc \
  ast/nodes/ASTNode_Transfer.cc
