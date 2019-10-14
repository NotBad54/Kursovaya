#include "tokens.h"

void CreateSetOfDelimiters()
{
    for (size_t i = 0; i < delimiters.size(); i++)
        DelimSet.insert(delimiters[i]);
}

bool IsDelimiter(char sym)
{
    return DelimSet.count(sym) > 0;
}

void CreateTokensFromExpression(string& expr, tokens& texpr)
{
    CreateSetOfDelimiters();
    string ex = expr + " ";
    string name;
    size_t i = 0;
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

    for (size_t j = 0; j < texpr.size(); j++) {
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
            if (j < texpr.size() - 1 && texpr[j + 1].name[0] == '[') {
                texpr[j].type = mas;
            }
            continue;
        }

        if (isalpha(texpr[j].name[0])) {
            if (j < texpr.size() - 1 && texpr[j + 1].name[0] == '(') {
                texpr[j].type = func;
            }
            continue;
        }

        texpr[j].type = op;
    }

    for (size_t j = 0; j < texpr.size(); j++) {
        if (texpr[j].name == "-" && (j == 0 || texpr[j - 1].type == op_br)) {
            texpr[j].name = "opposite";
        }
        if (texpr[j].name == "!"
            && (j == texpr.size() - 1 || texpr[j + 1].type == cl_br
                || texpr[j + 1].type == op)) {
            texpr[j].name = "factorial";
        }
    }
}