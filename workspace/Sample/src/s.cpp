//============================================================================
// Name        : Sample.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "sample.h"
#include "samplet.h"
#include "samplet.cpp"
#include <sstream>

using namespace std;

Sample getSample() {
	return Sample();
}

int main(int argc, char *argv[]) {

	vector<long double> d1 = { 3.4, 62, 9.2 };
	vector<long double> d2 = { 5.4, 34, 7.8 };

	d1.swap(d2);
	for (vector<long double>::iterator it = d1.begin(); it != d1.end(); it++) {

		cout << " D1: " << *it << flush;
	}
	cout << endl;
	for (vector<long double>::iterator it = d2.begin(); it != d2.end(); it++) {

		cout << " D2: " << *it << flush;
	}

	cout << endl;
	Sample samp = { { 3.4, 62, 9.2 } };
	Sample samp2 = Sample( { 5.4, 34, 7.8 });
	Sample samp3( { 2.2, 26, 82.4, 11.8, 9.2 });

	cout << (samp == samp2) << endl;

	samp2[2] = 28.4;
	cout << samp2[2] << endl;

	samp3[ { 23.5, 6, 2.1, 7.3, 8.2 }];
	samp3.print();

	//	for (vector<long double>::iterator it = samp.y.begin(); it != samp.y.end(); it++) {
	//
	//		cout << *it << endl;
	//	}


	//samplet<int> samplet({2, 5, 74, 12, 35, 11, 26});
		//samplet<string> samplet2 = samplet<string>({"dd", "sd", "cd"});



	vector<int> yy = { 2, 5, 74, 12, 35 };
	samplet<int> vc(yy);
	samplet<string> vc2 = samplet<string> ( { "dd", "sd", "cd" });
	samplet<string> vc3( { "dd", "sd", "cd" });

	vc2 = vc3;

	samplet<int> samp4;
	samp4.set_data(yy);

	cout << (samp4==vc) << endl;

	return 0;
}
