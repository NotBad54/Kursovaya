#include "refs.h" 


typedef map<string, double> Variables;

typedef map<string, vector<double> > Massives;


void ReadExpressionFromStream(ifstream &inp, string &expr, Variables &var, Massives &mas) {
	getline(inp, expr);
	string temp;
	int pos;

	while (!inp.eof()) {
		getline(inp, temp);
	
		pos = temp.find('=');
		if (pos > 0) {
			string name = temp.substr(0, pos);
			double value = atof(temp.substr(pos + 1).c_str());
			var[name] = value;
		}
		
		pos = temp.find('{');
		if (pos > 0) {
			string name = temp.substr(0, pos);
		
			int pos1 = pos, pos2;
			do {
				pos2 = temp.find(',');
				double value = atof(temp.substr(pos1 + 1, pos2).c_str());
				mas[name].push_back(value);
				if (pos2 == -1)
					break;
				temp[pos2] = ' ';
				pos1 = pos2;
			} while (pos2 > 0);
		}
	}
	return;
}
