#include <iostream>
#include <fstream>//file stream
#include "samplet.h"
#include "samplet.cc"

//#include "sample.h"

using namespace std;



int main(int argc, char *argv[]) {
	/* an empty sample object - initialise with a vector once
	 * you have defined the sample constructor that takes a
	 * vector
	 */
	//	sample a_sample;
	//
	//	cout << "Before city_test()\n";
	//	city_test(a_sample);
	//	cout << "After city_test()\n";



	samplet<int> si = {34, 12, 5, 129, 10};
	samplet<double> sd = {2.3, 18.5, 32.9, 5.8};
	samplet<float> sf = {3.323, 13.498, 30.92, 15.268, 4.03};
	samplet<string> ss = {"lexi", "romeo", "syndie", "abdul", "omar", "raul"};

	//sample s = {22, 12, 2.9, 1.8};


	/*
	string outputFile = "cwk-input01.txt";

	fstream outFile;
	outFile.open(outputFile, ios::out);

	if (outFile.is_open()) {

		while (cin >> s)

			//2
			outFile << s << endl

			//3
					<< "Size: " << s.get_size() << endl

			//4
					<< "Smallest number: " << s.minimum() << endl

			//5
					<< "Largest number: " << s.maximum() << endl

			//6
					<< "Range: " << s.range() << endl

			//7
					<< "Mid-Range: " << s.midrange() << endl

			//11
					<< "Median: " << s.median() << endl

			//8
					<< "Sum: " << s.sum() << endl

			<< "Mean: " << s.mean() << endl

			//9
					<< "Variance: " << s.variance() << endl

			<< "Mode: " << s.mode() << endl

			//10
					<< "Standard Deviation: " << s.std_deviation() << endl << endl;

		if (cin.bad())
			cerr << "\nBad input\n\n";

		outFile.close();

	} else { cerr << "Could not create file " << outputFile << endl; }

*/
	return 0;
}

