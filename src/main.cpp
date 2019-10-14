﻿#include "refs.h"
#include "postfix.h"
#include "result.h"
#include "stdafx.h"
#include "tokens.h"

using namespace std;

tokens texpr, pexpr;
Variables expvars;
Massives expmasvars;
string expr;
ifstream file("../Kursovaya/test.txt");

int main()
{
    ReadExpressionFromStream(file, expr, expvars, expmasvars);
    file.close();

    cout << "Expr:" << endl;
    cout << expr << endl;

    Variables::iterator it;
    for (it = expvars.begin(); it != expvars.end(); it++) {
        cout << it->first << '=' << it->second << endl;
    }
    Massives::iterator it1;
    for (it1 = expmasvars.begin(); it1 != expmasvars.end(); it1++) {
        cout << it1->first << '{';
        for (size_t i = 0; i < it1->second.size(); i++) {
            if (i == it1->second.size() - 1) {
                cout << it1->second[i];
            } else {
                cout << it1->second[i] << ',';
            }
        }
        cout << '}' << endl;
    }
    cout << endl;

    CreateTokensFromExpression(expr, texpr);

    CreatePostfixFromTokens(texpr, pexpr);

    cout << "Result:" << endl;
    ResultExpr(pexpr, expvars, expmasvars);

    texpr.clear();
    pexpr.clear();
    expvars.clear();
    expmasvars.clear();
    expr.clear();

    return 0;
}
