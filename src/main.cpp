#include "stdafx.h"
#include "refs.h"
#include "tokens.h"
#include "postfix.h"
#include "result.h"



using namespace std;


int main()
{
tokens texpr, pexpr;
	Variables expvars;
	Massives expmasvars;
	string expr;
	ifstream file("test.txt");

	ReadExpressionFromStream(file, expr, expvars, expmasvars);

	cout << "Expr:" << endl;
	cout << expr << endl;

	Variables::iterator it;
	for (it = expvars.begin(); it != expvars.end(); it++)
		cout << it->first << '=' << it->second << endl;

	Massives::iterator it1;
	for (it1 = expmasvars.begin(); it1 != expmasvars.end(); it1++) {
		cout << it1->first << '{';
		for (int i = 0; i < it1->second.size(); i++) {
			if (i == it1->second.size() - 1)
				cout << it1->second[i];
			else
				cout << it1->second[i] << ',';
		}
		cout << '}' << endl;
	}
	cout << endl;

	cout << ResultExpr(pexpr, expvars, expmasvars) << endl;

	system("PAUSE");
	return 0;
}
