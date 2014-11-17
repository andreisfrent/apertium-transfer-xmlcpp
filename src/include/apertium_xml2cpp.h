#ifndef _APERTIUM_XML2CPP_APERTIUM_XML2CPP_H
#define _APERTIUM_XML2CPP_APERTIUM_XML2CPP_H

// NOTE NOTE NOTE
// The order of headers in this file is important.

#include "../error/Error.h"

#include "../misc/StringUtil.h"

#include "../parsing/XMLNode.h"
#include "../parsing/XMLTree.h"
#include "../parsing/XMLParser.h"
#include "../parsing/XMLUtil.h"

#include "../ast/nodes/ASTNode.h"
#include "../ast/nodes/Statement.h"
#include "../ast/nodes/ASTNode_CallMacro.h"
#include "../ast/nodes/ASTNode_CodeBlock.h"
#include "../ast/nodes/ASTNode_Rule.h"
#include "../ast/nodes/ASTNode_Rules.h"
#include "../ast/nodes/ASTNode_Macro.h"
#include "../ast/nodes/ASTNode_GlobalVariables.h"
#include "../ast/nodes/ASTNode_GlobalLists.h"
#include "../ast/nodes/ASTNode_GlobalMacros.h"
#include "../ast/nodes/ASTNode_Categories.h"
#include "../ast/nodes/ASTNode_Attributes.h"
#include "../ast/nodes/ASTNode_Stage.h"
#include "../ast/nodes/ASTNode_StagePostchunk.h"
#include "../ast/nodes/ASTNode_StageTransfer.h"
#include "../ast/nodes/ASTNode_StageInterchunk.h"
#include "../ast/nodes/ASTNode_Root.h"

#include "../ast/AST.h"

#endif
