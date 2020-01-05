#pragma once

#include "FastLexerForCpp.h"
#include <string>

void UnitTestLexer()
{
	using namespace SNL::FastLexerForCppConst;
	char text[] = "\"1.01\" number 0 123 12.4 0x12112 /*fdffffffffff*/!";
	Token tokens[] =
	{
		TOKEN_STRING,
		TOKEN_ID,
		TOKEN_ICON,
		TOKEN_ICON,
		TOKEN_FCON,
		TOKEN_ICON,
		TOKEN_COMMENT,
		TOKEN_BOOL_UNOP
	};

	std::cout << text<< std::endl;
	SNL::FastLexerForCpp Lexer;
	Lexer.StartParse(text);
	int Current = 0;
	while (int Token=Lexer.Lex())
	{
		SNL_ASSERT(Token == tokens[Current++]);
		std::string s((char*)Lexer.TokenStart, (char*)Lexer.CurrentPoint);
		std::cout << Token << "   "<<s << " "<< TokenNames[Token]<<std::endl;
	}
}