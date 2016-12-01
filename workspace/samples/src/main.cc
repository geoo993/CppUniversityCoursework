//#include <iostream>

#include "sample.h"
#include "samplet.h"
#include "samplet.cc"

using namespace std;

int main(int argc, char *argv[]) {

	sample a_sample;
	//samplet<long double> a_sample;
	//samplet<double> a_sample;
	//samplet<float> a_sample;
	//samplet<int> a_sample;


	//<6: 7 11 2 13 3 5 >
	string special_str = "<2: 1.18973e+4932 1.18973e+4932 >";
	string outputFile = "cwk-input01.txt";

	fstream outFile;
	outFile.open(outputFile, ios::out);

	 if (outFile.is_open()) {

		 while (cin >> a_sample){

			 //this code for testing sample file
			 a_sample.test(a_sample,outFile, cout);

			 cout << "The output is written in ---> " << outputFile << endl;

			 {
				 //question 14: What does your non-generic program print for the following input
				 a_sample.compute_set_sample(special_str, a_sample);
				 a_sample.test(a_sample,outFile, cout);

				 outFile << "This long double number (1.18973e+4932) is the maximum floating number range of a long double. "
						 << "You can prove this by doing: std::numeric_limits< long double >::max() is 1.18973e+4932). "
						 << "Setting this on an integer will give you: -2147483648, "
						 << "which is the minimum limit value of a signed long integer. "
						 << "when set on other types like double or float will just give you: inf, which is the special value \"positive infinity\", "
						 << "a number that I can simply describe as very large." << endl;
			 }


		 }
		 if (cin.bad())
			 cerr << "\nBad input\n\n";

		 outFile.close();

	 } else { cerr << "Cannot create text file " << outputFile << endl; }





	return 0;
}
