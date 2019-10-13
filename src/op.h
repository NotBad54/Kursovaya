#pragma once
#ifndef _OP_H
#define _OP_H
#include "stdafx.h"
#include"postfix.h"
#include "tokens.h"
#include "refs.h"

using namespace std;

long long int fact(int n);
double op_plus(stack <double> &s);
double op_minus(stack <double> &s);
double op_mul(stack <double> &s);
double op_div(stack <double> &s);
double op_deg(stack <double> &s);
double op_opposite(stack <double> &s);
double op_factorial(stack <double> &s);
double op_odiv(stack <double> &s);
double op_and(stack <double> &s);
double op_or(stack <double> &s);
double op_not(stack <double> &s);
double op_sin(stack <double> &s);
double op_cos(stack <double> &s);
double op_tan(stack <double> &s);
double op_asin(stack <double> &s);
double op_acos(stack <double> &s);
double op_atan(stack <double> &s);

#endif