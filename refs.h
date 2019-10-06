#pragma once
#ifndef _REFS_H
#define _REFS_H
<<<<<<< HEAD
#include "stdafx.h""


||||||| merged common ancestors
#include <string>
#include <fstream>
#include <vector>
#include <map>


=======
#include "stdafx.h"
>>>>>>> a2e9da40fbbc9bd0e511cb3104022ddd36bf1b32

using namespace std;

typedef map<string, double> Variables;
typedef map<string, vector<double> > Massives;

void ReadExpressionFromStream(ifstream &inp, string &expr, Variables &var, Massives &mas);

#endif
