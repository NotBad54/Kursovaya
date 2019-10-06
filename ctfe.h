#pragma once
#ifndef _CTFE_H
#define _CTFE_H
#include <string>
#include <vector>
#include <set>


using namespace std;

enum tokentype;
typedef vector<token> tokens;
void CreateSetOfDelimiters();
void CreateTokensFromExpression(string &expr, tokens &texpr);

#endif