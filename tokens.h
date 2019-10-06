#pragma once
#ifndef _TOKENS_H
#define _TOKENS_H
#include "stdafx.h"

using namespace std;


 enum tokentype {
		var, num, op_br, cl_br, func, op, mas, op_sbr, cl_sbr
	};
	struct token {
		string name;
		tokentype type;

		token(string str, tokentype typ) {
			name = str;
			type = typ;
		}
		token() {}
	};

	typedef vector<token> tokens;
		
	static set<char> DelimSet;
	static const string delimiters = " ()+/*-^&|!%[]";


void CreateSetOfDelimiters();
bool IsDelimiter(char sym);
void CreateTokensFromExpression(string &expr, tokens &texpr);

#endif