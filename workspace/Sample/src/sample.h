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
#include <sstream>
#include <cassert>

using namespace std;


class Sample {
private:

	const int N { 6 };

public:
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

	friend bool operator== (const Sample &l, const Sample &r);
	friend bool operator!= (const Sample &l, const Sample &r);
	friend bool operator> (const Sample &l, const Sample &r);
	friend bool operator<= (const Sample &l, const Sample &r);
	friend bool operator< (const Sample &l, const Sample &r);
	friend bool operator>= (const Sample &l, const Sample &r);
	long double &operator[] (const unsigned index);
	const long double &operator[] (const unsigned index) const;
	void operator[] (vector<long double> y);

	int get_N() const;
	unsigned int get_size() const;
	void set_data(vector<long double> y);
	void insert_data (long double value);
	void remove_unwanted_characters(string &str);
	vector<long double> get_data() const;
	long double find_data(int value);
	long double minimum();
	long double maximum();
	long double range();
	long double midrange();
	long double sum();
	long double mean();
	long double median();
	long double mode();
	long double variance();
	long double std_deviation();
	void sort();//ascending order
	long double calculateAverage(const long double &a, const long double &b);


	void print() const;

	virtual ~Sample();

	// the put to (<<) operator, so you can use objects of this class with cout
	friend ostream &operator<<(ostream &out, const Sample &test);
	friend istream &operator>>(istream &in, Sample &sample);


};



#endif /* SAMPLE_H_ */
