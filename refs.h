#pragma once
#ifndef _REFS_H
#define _REFS_H
#include <string>
#include <fstream>
#include <vector>
#include <map>



using namespace std;

typedef map<string, double> Variables;
typedef map<string, vector<double> > Massives;
void ReadExpressionFromStream(ifstream &inp, string &expr, Variables &var, Massives &mas);

#endif