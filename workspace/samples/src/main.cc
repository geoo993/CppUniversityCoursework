
#include <iostream>
#include "samplet.h"
#include "samplet.cc"

//#include "sample.h"

#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <string>


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

///*
	samplet<int> s;
	//samplet<double> s;
	//samplet<float> s;

	//sample s;
	while (cin  >> s)

		 //2
		 cout << s << endl

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
		 << "Standard Deviation: " << s.std_deviation() << endl;

	if (cin.bad()) cerr << "\nBad input\n\n";
//*/




	return 0;
}
