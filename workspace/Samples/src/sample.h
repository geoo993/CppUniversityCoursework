/*
 * sample.h
 *
 *  Created on: 4 Nov 2016
 *      Author: GeorgeQuentin
 */

#ifndef SAMPLE_H_
#define SAMPLE_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Sample {
private:
	int input;
	const int N { 100 };
	vector <long double> y;


public:

	Sample();

	Sample(vector<long double> y);

	//Sample(const Sample &other)= default;//copy constructor
	Sample(const Sample &other);

	Sample(Sample &&other);//move copy constructor

	//Sample &operator=(const Sample &other)= default;//assigment operator to default
	Sample &operator=(const Sample &other);//assignment constructor

	Sample &operator=(Sample &&other);//move assignment operator


	int get_N();
	int get_size();
	void set_data(vector<long double> y);
	vector<long double> get_data();
	long double find_data(int value);
	long double minimum();
	long double maximum();
	long double range();
	long double midRange();
	long double sum();
	long double mean();
	long double median();
	long double mode();
	long double variance();
	long double std_deviation();
	void sort();//ascending order
	long double calculateAverage(const long double &a, const long double &b);


	Sample print();
	void normalPrint();

	virtual ~Sample();

	// the put to (<<) operator, so you can use objects of this class with cout
	friend ostream &operator<<(ostream &out, const Sample &test);
	friend istream &operator>>(istream &in, const Sample &sample);


};



#endif /* SAMPLE_H_ */
