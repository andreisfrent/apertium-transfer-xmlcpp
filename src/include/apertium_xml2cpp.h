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
#include "../ast/nodes/CallMacro.h"
#include "../ast/nodes/CodeBlock.h"
#include "../ast/nodes/Rule.h"
#include "../ast/nodes/Rules.h"
#include "../ast/nodes/Macro.h"
#include "../ast/nodes/GlobalVariables.h"
#include "../ast/nodes/GlobalLists.h"
#include "../ast/nodes/GlobalMacros.h"
#include "../ast/nodes/Categories.h"
#include "../ast/nodes/Attributes.h"
#include "../ast/nodes/Stage.h"
#include "../ast/nodes/StagePostchunk.h"
#include "../ast/nodes/StageTransfer.h"
#include "../ast/nodes/StageInterchunk.h"
#include "../ast/nodes/Root.h"

#include "../ast/AST.h"

#endif
