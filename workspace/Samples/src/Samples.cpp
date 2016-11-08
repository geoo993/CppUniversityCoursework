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
#include <memory.h>

using namespace std;

Sample getSample() {
	return Sample();
}


//int main() {
int main(int argc, char *argv[]) {

	vector<long double> vec = { 10.3, 35, 7.4 };

	Sample sample(vec);

	Sample sample2 = getSample();

	Sample sample3 = sample2;
	sample3 = sample;
	sample3 = getSample();

	//1
	sample.print();

	vector<long double> vec2 = { 10.3, 15.3, 7.4, 6.2, 38.5, 2.6, 12.4, 7.4 };
	sample.set_data(vec2);

	//2
	cout << sample.print() << endl;

	//3
	sample.get_data();
	Sample sample4(sample.get_data());

	cout << endl;

	cout << "Size " << sample.get_size() << endl;

	//4
	cout << endl;
	cout << "Smallest number: " << sample.minimum() << endl;

	//5
	cout << endl;
	cout << "Largest number: " << sample.maximum() << endl;

	//6
	cout << endl;
	cout << "Range: " << sample.range() << endl;

	//7
	cout << endl;
	cout << "Mid-Range: " << sample.midRange() << endl;

	//8
	cout << endl;
	cout << "Sum: " << sample.sum() << endl;

	cout << endl;
	cout << "Mean: " << sample.mean() << endl;

	//9
	cout << endl;
	cout << "Variance: " << sample.variance() << endl;

	//sample.print();
	cout << endl;
	cout << "Mode: " << sample.mode() << endl;

	//10
	cout << endl;
	cout << "Standard Deviation: " << sample.std_deviation() << endl;

	//11
	cout << endl;
	cout << "Median: " << sample.median() << endl;

	//12
	Sample sample7;
	cin >> sample7;

	//13
	vector<int> v = { 7, 11, 2, 13, 3, 5};
	Samplet<int> samplet(v);
	samplet.print();
	Samplet<int> samplet2(samplet.get_data());
	cout << "Samplet Size " << samplet.get_size() << endl;
	cout << "Samplet Smallest number: " << samplet.minimum() << endl;
	cout << "Samplet Largest number: " << samplet.maximum() << endl;
	cout << "Samplet Range: " << samplet.range() << endl;
	cout << "Samplet Mid-Range: " << samplet.midRange() << endl;
	cout << "Samplet Sum: " << samplet.sum() << endl;
	cout << "Samplet Mean: " << samplet.mean() << endl;
	cout << "Samplet Variance: " << samplet.variance() << endl;
	cout << "Samplet Mode: " << samplet.mode() << endl;
	cout << "Samplet Standard Deviation: " << samplet.std_deviation() << endl;
	cout << "Samplet Median: " << samplet.median() << endl;
	Samplet<int> samplet3;
	cin >> samplet3;


	return 0;
}


