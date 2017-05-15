#include <iostream>
#include <fstream>
#include <vector>
#include "Taxi.h"
#include "Trajectory.h"
#include <string>
using namespace std;

void x2val(int *i) {
	*i *= 2;
}

bool to_bool(string const& s) {
	return s != "0";
}

class foo {
private:
	int intp;
public:
	foo(int i) {
		intp = i;
	}
};

int main() {
	Trajectory tmpTra;
	ifstream inputfile("37.csv");
	string str1;
	string str2;
	string str3;
	string str4;
	string str5;
	vector<Taxi> *lstTx = tmpTra.getlstTaxi();
	int c = 0;
	while (inputfile.good()) {
		getline(inputfile, str1, ',');
		getline(inputfile, str2, ',');
		getline(inputfile, str3, ',');
		getline(inputfile, str4, ',');
		getline(inputfile, str5);
		lstTx->push_back(Taxi(stoi(str1), Coord(stod(str4), stod(str5)), to_bool(str2), DateTime(), 1));
		cout << c << ": " << lstTx->at(c).getCoord().lat << " " << lstTx->at(c).getCoord().lng <<  endl;
		c++;
	}
}