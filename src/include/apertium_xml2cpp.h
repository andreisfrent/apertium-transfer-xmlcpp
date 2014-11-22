#ifndef _APERTIUM_XML2CPP_APERTIUM_XML2CPP_H
#define _APERTIUM_XML2CPP_APERTIUM_XML2CPP_H

// NOTE NOTE NOTE
// The order of headers in this file is important.

#include "../error/Error.h"

// Misc: strings.
#include "../misc/StringUtil.h"

// XML related headers.
#include "../parsing/XMLNode.h"
#include "../parsing/XMLTree.h"
#include "../parsing/XMLParser.h"
#include "../parsing/XMLUtil.h"

// AST node base class.
#include "../ast/nodes/ASTNode.h"

// Different AST node types.
#include "../ast/nodes/Statement.h"
#include "../ast/nodes/Condition.h"
#include "../ast/nodes/LValue.h"
#include "../ast/nodes/RValue.h"

// Base classes for cross-type nodes.
#include "../ast/nodes/VariableBase.h"
#include "../ast/nodes/ClipBase.h"

// Multiple statements.
#include "../ast/nodes/CodeBlock.h"

// AST: Statements.
#include "../ast/nodes/CallMacro.h"
#include "../ast/nodes/Choose.h"
#include "../ast/nodes/Let.h"
#include "../ast/nodes/ModifyCase.h"
#include "../ast/nodes/Out.h"
#include "../ast/nodes/Append.h"

// AST: Conditions
#include "../ast/nodes/And.h"
#include "../ast/nodes/Or.h"
#include "../ast/nodes/Not.h"
#include "../ast/nodes/Equal.h"
#include "../ast/nodes/SubstrCmp.h"
#include "../ast/nodes/SubstrCmpList.h"

// AST: LValues.
#include "../ast/nodes/Variable_LValue.h"
#include "../ast/nodes/Clip_LValue.h"

// AST: RValues.
#include "../ast/nodes/Variable_RValue.h"
#include "../ast/nodes/Clip_RValue.h"
#include "../ast/nodes/Lit.h"
#include "../ast/nodes/B.h"
#include "../ast/nodes/Lu.h"
#include "../ast/nodes/Mlu.h"
#include "../ast/nodes/Concat.h"
#include "../ast/nodes/Chunk.h"

#include "../ast/nodes/Rule.h"
#include "../ast/nodes/Rules.h"
#include "../ast/nodes/Macro.h"
#include "../ast/nodes/GlobalVariables.h"
#include "../ast/nodes/GlobalLists.h"
#include "../ast/nodes/GlobalMacros.h"
#include "../ast/nodes/Categories.h"
#include "../ast/nodes/Attributes.h"
#include "../ast/nodes/Stage.h"
#include "../ast/nodes/Postchunk.h"
#include "../ast/nodes/Transfer.h"
#include "../ast/nodes/Interchunk.h"
#include "../ast/nodes/Root.h"

#include "../ast/AST.h"

#endif
