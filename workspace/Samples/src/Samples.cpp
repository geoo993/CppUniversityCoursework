//============================================================================
// Name        : Samples.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "sample.h"
#include "samplet.h"
#include <sstream>

using namespace std;

Sample getSample() {
	return Sample();
}

//int main() {
int main(int argc, char *argv[]) {


	Sample s;

	while (cin >> s) {


	 //1
	 s.print();

	 //2
	 cout << s << endl;

	 //3
	 cout << "Size: " << s.get_size() << endl;

	 //4
	 cout << "Smallest number: " << s.minimum() << endl;

	 //5
	 cout << "Largest number: " << s.maximum() << endl;

	 //6
	 cout << "Range: " << s.range() << endl;

	 //7
	 cout << "Mid-Range: " << s.midrange() << endl;

	 //8
	 cout << "Sum: " << s.sum() << endl;

	 cout << "Mean: " << s.mean() << endl;

	 //9
	 cout << "Variance: " << s.variance() << endl;

	 cout << "Mode: " << s.mode() << endl;

	 //10
	 cout << "Standard Deviation: " << s.std_deviation() << endl;

	 //11
	 cout << "Median: " << s.median() << endl;


//	 cout << s << endl << s.get_size() << endl << s.minimum() << endl << s.range() << endl << s.median()
//	 			<< endl << s.sum() << endl << s.variance() << endl << s.maximum() << endl
//	 			<< s.midrange() << endl << s.mode() << endl << s.mean() << endl << s.std_deviation()
//	 			<< endl;

	 break;

	 if (cin.bad()){
		cerr << "\nBad input\n\n";
	 }

	}

	cout << endl;

	///*
	Samplet<float> samplet;

	while (cin >> samplet) {

	 samplet.print();
	 cout << "Samplet Size " << samplet.get_size() << endl;
	 cout << "Samplet Smallest number: " << samplet.minimum() << endl;
	 cout << "Samplet Largest number: " << samplet.maximum() << endl;
	 cout << "Samplet Range: " << samplet.range() << endl;
	 cout << "Samplet Mid-Range: " << samplet.midrange() << endl;
	 cout << "Samplet Sum: " << samplet.sum() << endl;
	 cout << "Samplet Mean: " << samplet.mean() << endl;
	 cout << "Samplet Variance: " << samplet.variance() << endl;
	 cout << "Samplet Mode: " << samplet.mode() << endl;
	 cout << "Samplet Standard Deviation: " << samplet.std_deviation() << endl;
	 cout << "Samplet Median: " << samplet.median() << endl;

	 break;

	 if (cin.bad()){
	 	cerr << "\nBad input\n\n";
	 }

	}
	//*/


/*

	 //14
	 //vector<long double> vec3 = {1.18973e+4932, 1.18973e+4932};
	 //Sample s2(vec3);
	 //s2.print();

	 //PRINT
	 //magnitude of floating-point constant too large for type 'double'; maximum is 1.7976931348623157E+308 [-Wliteral-range]
	 //< 2: inf, inf,  >

	 //Do you know what the problem is? (Answer in sample.cc as a comment) [2]????????
	 */

	return 0;
}

