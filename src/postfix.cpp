#include "postfix.h"

void CreatePrior() {
	prior["+"] = 10;
	prior["-"] = 10;
	prior["*"] = 20;
	prior["/"] = 20;
	prior["^"] = 30;
	prior["opposite"] = 10;
	prior["factorial"] = 30;
	prior["%"] = 20;
	prior["&"] = 5;
	prior["|"] = 5;
	prior["!"] = 40;
}


void CreatePostfixFromTokens(tokens &texpr, tokens &pexpr) {
	
	CreatePrior();
	stack <token> TStack;
	for (int i = 0; i < texpr.size(); i++) {
		switch (texpr[i].type) {
		case var:
		case num:
			pexpr.push_back(texpr[i]);
			break;

		case op_br:
			TStack.push(texpr[i]);
			break;

		case cl_br:
			while (TStack.top().type != op_br) {
				pexpr.push_back(TStack.top());
				TStack.pop();
			}
			TStack.pop();
			break;

		case op_sbr:
			TStack.push(texpr[i]);
			break;

		case cl_sbr:
			while (TStack.top().type != op_sbr) {
				pexpr.push_back(TStack.top());
				TStack.pop();
			}
			TStack.pop();
			break;

		case op:
			if (TStack.size()) {
				while (TStack.size() && ((TStack.top().type == op && prior[texpr[i].name] <= prior[TStack.top().name]) ||
					TStack.top().type == func ||
					TStack.top().type == mas)) {
					pexpr.push_back(TStack.top());
					TStack.pop();
				}
			}
			TStack.push(texpr[i]);
			break;

		case mas:
			while (TStack.size() && TStack.top().type == mas) {
				pexpr.push_back(TStack.top());
				TStack.pop();
			}
			TStack.push(texpr[i]);
			break;

		case func:
			while (TStack.size() && TStack.top().type == func) {
				pexpr.push_back(TStack.top());
				TStack.pop();
			}
			TStack.push(texpr[i]);
			break;
		}
	}

	while (TStack.size()) {
		pexpr.push_back(TStack.top());
		TStack.pop();
	}

	return;
}