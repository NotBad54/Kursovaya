#pragma once
#ifndef _POSTFIX_H
#define _POSTFIX_H
#include "stdafx.h"
#include "tokens.h"
#include "op.h"

static map <string, int> prior;

void CreatePrior();
void CreatePostfixFromTokens(tokens &texpr, tokens &pexpr);

#endif