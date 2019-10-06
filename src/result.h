#pragma once
#ifndef _RESULT_H
#define _RESULT_H
#include "stdafx.h"
#include "postfix.h"
#include "tokens.h"

using namespace std;

typedef double(*func_type)(stack<double> &);
typedef map<string, func_type> Ops;
static Ops ops;

void CreateOps();
double ResultExpr(tokens &pexpr, Variables &expvars, Massives &varmas);

#endif

