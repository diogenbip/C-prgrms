#include <iostream>
#include <vector>
#include <list>
#include "Adaptor.h"
#include "Lexer.h"




using namespace std;




	Adaptor::Adaptor()
	{
	}
	Adaptor::Adaptor(list<Lexem> p) {
		
		label = true;
		for (auto lex = p.begin(); lex != p.end(); lex++)
		{
			l.push_back(Check(lex->token_class,lex->value));
		}
	}

	std::string Adaptor::Check(LexemClass lc,std::string val) {
		if (lc == KeyWrd)
		{
			if (val == "dim")
			{
				label = false;
				return "dim";
			}
			else if (val == "as")
			{
				return "as";
			}
			else if (val == "int")
			{
				return "int";
			}
			else if (val == "mset")
			{
				return "mset";
			}
			else if (val == "let")
			{
				label = false;
				return "let";
			}
			else if (val == "if")
			{
				label = false;
				return "if";
			}
			else if (val == "goto")
			{
				label = true;
				return "goto";
			}
			else if (val == "for")
			{
				label = false;
				return "for";
			}
			else if (val == "to")
			{
				return "to";
			}
			else if (val == "next")
			{
				return "next";
			}
			else if (val == "read")
			{
				label = false;
				return "read";
			}
			else if (val == "write")
			{
				label = false;
				return "write";
			}
			else if (val == "jump")
			{
				label = true;
				return "jump";
			}
			else if (val == "switch")
			{
				return "switch";
			}
			else if (val == "end") 
			{
				return "end";
			}
			else if (val == "trow") 
			{
				return "trow";
			}
			else if (val == "rem")
			{
				return "rem";
			}
			else if (val == "case")
			{
				return "case";
			}
			else if (val == "break")
			{
				return "break";
			}
			else if (val == "else")
			{
				return "else";
			}
			else if (val == "adding")
			{
				return "adding";
			}
			else if (val == "dif")
			{
				return "Dif";
			}
			else if (val == "sdif")
			{
				return "SDif";
			}
			else if (val == "cross")
			{
				return "Cross";
			}
			else if (val == "un")
			{
				return "Un";
			}
		}
		else if (lc == Semm)
		{
			label = true;
			return "SEM";
		}
		else if (lc == Ident)
		{
			if (label) {
				label = false;
				return "L";
			}
			else {
				return "v";
			}
		}
		else if (lc == comma) 
		{
			return "COMMA";
		}
		else if (lc == Equal)
		{
			label = false;
			return "Equal";
		}
		else if (lc == lab)
		{
			label = true;
			return "lab";
		}
		else if (lc == rab)
		{
			label = false;
			return "rab";
		}
		else if (lc == lb)
		{
			label = false;
			return "lb";
		}
		else if (lc == rb)
		{
			return "rb";
		}
		else if (lc == Const)
		{
			return "c";
		}
		else if (lc == COLON)
		{
			return "COLON";
		}
		else if(lc==BOOL)
		{
			if(val == "==")
			{
				return "Eq_Equal";
			}
			else if (val == "!=")
			{
				return "Not_Equal";
			}
			else if (val == ">=")
			{
				return "More_Equal";
			}
			else if (val == "<=")
			{
				return "Less_Equal";
			}
			else if (val == ">")
			{
				return "More_";
			}
			else if (val == "<")
			{
				return "Less_";
			}

		}
		else if (lc == Ar_Op)
		{
			if (val == "+")
			{
				return "Plus";
			}
			else if (val == "-")
			{
				return "Minus";
			}
			else if (val == "*")
			{
				return "Multiply";
			}
			else if (val == "/")
			{
				return "Div";
			}
			else if (val == "%")
			{
				return "Mod";
			}
		}

			
	}


