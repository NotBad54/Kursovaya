#pragma once
#ifndef _CTFE_H
#define _CTFE_H
#include <string>
#include <vector>
#include <set>


using namespace std;

typedef vector<token> tokens;
void CreateSetOfDelimiters();
void CreateTokensFromExpression(string &expr, tokens &texpr);

#endif