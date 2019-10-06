#include "ctfe.h"

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

set<char> DelimSet;

const string delimiters = " ()+/*-^&|!%[]";

void CreateSetOfDelimiters() {
for (int i = 0; i < delimiters.size(); i++)
DelimSet.insert(delimiters[i]);
return;
}


bool IsDelimiter(char sym) {
return DelimSet.count(sym) > 0;
}


void CreateTokensFromExpression(string &expr, tokens &texpr) {
CreateSetOfDelimiters();
string ex = expr + " ";
string name;


int i = 0;
while (i < ex.size() - 1) {
name = "";

if (IsDelimiter(ex[i])) {
if (ex[i] == ' ') {
i++;
continue;
}
name = ex[i];
i++;
}

else {
while (!IsDelimiter(ex[i])) {
name += ex[i];
i++;
}
}
texpr.push_back(token(name, var));
}

for (int j = 0; j < texpr.size(); j++) {
if (texpr[j].name[0] == '[') {
texpr[j].type = op_sbr;
continue;
}
if (texpr[j].name[0] == ']') {
texpr[j].type = cl_sbr;
continue;
}
if (texpr[j].name[0] == '(') {
texpr[j].type = op_br;
continue;
}
if (texpr[j].name[0] == ')') {
texpr[j].type = cl_br;
continue;
}
if (isdigit(texpr[j].name[0])) {
texpr[j].type = num;
continue;
}


if (isalpha(texpr[j].name[0])) {
if (j < texpr.size() - 1 && texpr[j + 1].name[0] == '[')
texpr[j].type = mas;
//continue;
}

if (isalpha(texpr[j].name[0])) {
if (j < texpr.size() - 1 && texpr[j + 1].name[0] == '(')
texpr[j].type = func;
continue;
}

texpr[j].type = op;
}


for (int j = 0; j < texpr.size(); j++) {
if (texpr[j].name == "-" && (j == 0 || texpr[j - 1].type == op_br))
texpr[j].name = "opposite";
if (texpr[j].name == "!" && (j == texpr.size() - 1 || texpr[j + 1].type == cl_br || texpr[j + 1].type == op))
texpr[j].name = "factorial";
}

return;
}