/** \file
 *  This C++ header file was generated by $ANTLR version 3.4.1-SNAPSHOT
 *
 *     -  From the grammar source file : T.g
 *     -                            On : 2012-09-17 18:17:42
 *     -                for the parser : TParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C++ language generator and runtime by Gokulakannan Somasundaram ( heavy lifting from C Run-time by Jim Idle )
 *
 *
 * The parser 
TParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Gokulakannan Somasundaram. 
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_TParser_H
#define _TParser_H
/* =============================================================================
 * Standard antlr3 C++ runtime definitions
 */
#include    <antlr3.hpp>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */


   #include "TLexer.hpp"




#ifdef	WIN32
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
	namespace 	User  {


typedef TParserTraits TParserImplTraits;


class TParserTokens
{
public:
	/** Symbolic definitions of all the tokens that the 
parser
 will work with.
	 * \{
	 *
	 * Antlr will define EOF, but we can't use that as it it is too common in
	 * in C header files and that would be confusing. There is no way to filter this out at the moment
	 * so we just undef it here for now. That isn't the value we get back from C recognizers
	 * anyway. We are looking for ANTLR_TOKEN_EOF.
	 */
	enum Tokens 
	{
		EOF_TOKEN = TParserImplTraits::CommonTokenType::TOKEN_EOF
		, T__7 = 7 
		, T__8 = 8 
		, T__9 = 9 
		, T__10 = 10 
		, T__11 = 11 
		, T__12 = 12 
		, T__13 = 13 
		, T__14 = 14 
		, T__15 = 15 
		, ID = 4 
		, INT = 5 
		, WS = 6 
	};

};

/** Context tracking structure for 
TParser

 */
class TParser : public 
TParserImplTraits::BaseParserType
, public TParserTokens
{
public:
	typedef TParserImplTraits ImplTraits;
	typedef TParser ComponentType;
	typedef ComponentType::StreamType StreamType;
	typedef 
TParserImplTraits::BaseParserType
 BaseType;
	typedef ImplTraits::RecognizerSharedStateType<StreamType> RecognizerSharedStateType;
	typedef StreamType InputType;
	static const bool IsFiltered = false;

	/* ruleAttributeScopeDecl(scope)
	 */
	/* makeScopeSet()
	 */
	 /** Definition of the method scope variable tracking
	 *  structure. An instance of this structure is created by calling
	 *  TParser_methodPush().
	 */
	struct  methodScope
	{
	    /* =============================================================================
	     * Programmer defined variables...
	     */
	    /** name is visible to any rule called by method directly or indirectly.
	           *  There is also a stack of these names, one slot for each nested
	           *  invocation of method.  If you have a method nested within another
	           *  method then you have name strings on the stack.  Referencing
	           *  $method.name access the topmost always.  I have no way at the moment
	           *  to access earlier elements on the stack.
	           */
	          std::string name;

	    /* End of programmer defined variables
	     * =============================================================================
	     */
	};



private:	
    /* ruleAttributeScopeDef(scope)
     */
    StackType< methodScope >  m_method_stack;



public:
    TParser(InputType* instream);
    TParser(InputType* instream, RecognizerSharedStateType* state);

    void init(InputType* instream  );

     
     void
     program (); 
     
     void
     method (); 
     
     void
     body (); 
     
     void
     bstat (); 
     
     void
     expr (); 
     
     void
     mul (); 
     
     void
     atom (); 
    // Delegated rules

    const char *    getGrammarFileName();
    void            reset();
    ~TParser();

};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//

/* End of token definitions for TParser
 * =============================================================================
 */
/** } */

	}


#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
