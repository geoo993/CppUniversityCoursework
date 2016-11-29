#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <initializer_list>

using namespace std;
#include "city.hh"

class sample : public city {
  // DON'T CHANGE ANYTHING ABOVE THIS LINE!!! (You can add more includes)

private:
	unsigned int N = 0;

public:
	vector <long double> y;


public:

	sample();

	sample(vector<long double> y);

	sample(const initializer_list<long double> &y);

	sample(const sample &other);

	sample(sample &&other);

	sample &operator=(const sample &other);//assignment constructor

	sample &operator=(sample &&other);//move assignment operator

	friend bool operator== (const sample &l, const sample &r);
	friend bool operator!= (const sample &l, const sample &r);
	friend bool operator> (const sample &l, const sample &r);
	friend bool operator<= (const sample &l, const sample &r);
	friend bool operator< (const sample &l, const sample &r);
	friend bool operator>= (const sample &l, const sample &r);
	long double &operator[] (const unsigned index);
	const long double &operator[] (const unsigned index) const;
	void operator[] (vector<long double> y);

	void set_sample(string &str, sample &sample);
	unsigned int get_size() const;
	void set_data(vector<long double> y);
	void insert_data (long double value);
	bool check_unwanted_characters(string &str);
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
	void sort();
	long double calculateAverage(const long double &a, const long double &b);

	void print() const;

	friend ostream &operator<<(ostream &out, const sample &test);
	friend istream &operator>>(istream &in, sample &sample);

	virtual ~sample();

};

/* With normal (non-generic) code, the source (.cc) includes the header (.h). */
#endif
