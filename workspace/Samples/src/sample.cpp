/*
 * sample.cpp
 *
 *  Created on: 4 Nov 2016
 *      Author: GeorgeQuentin
 */

#include "sample.h"

Sample::Sample()
	: input(0) {
	//cout << "Constructor " << endl;
	y.resize(N);
}

Sample::Sample(vector<long double> y) {
	//cout << "Constructor with Parameters" << endl;
	this -> y.resize(N);
	this -> y = y;

	input = 0;
}

Sample::Sample(const Sample &other) {//copy constructor
	//cout << "Copy Constructor" << endl;
	y = other.y;
	input = other.input;
}

Sample::Sample(Sample &&other) { //this is a move copy constructor, usually you do not need const in R values references

	//cout << "Move Copy Constructor" << endl;
	y = other.y;
	input = other.input;
}

Sample &Sample::operator=(const Sample &other)//assignment constructor
{
	//cout << "Assignment Constructor" << endl;
	y = other.y;

	return *this;
}

Sample &Sample::operator=(Sample &&other) {// this is the move assignment operator

	//cout << "Move Assignment Constructor" << endl;
	y = other.y;

	return *this;
}

int Sample::get_N() {
	return this->N;
}

void Sample::set_data(vector<long double> y) {
	this->y = y;
}

//3
vector<long double> Sample::get_data() {
	return y;
}

void Sample::sort() {
	::sort(y.begin(), y.end());
}

int Sample::get_size() {
	return y.size();
}

long double Sample::find_data(int index) {

	if (index < get_size()) {
		return y[index];
	} else {
		return 0;
	}
}

long double Sample::minimum() {

	long double smallest = get_N();

	if (get_size() <= 0) {
		return 0;
	} else {
		if (y.begin() == y.end()) {
			//cout << "vector is empty " << endl;

			smallest = *(y.end());
			return smallest;

		} else {

			for (vector<long double>::iterator it = y.begin(); it != y.end(); it++) {

				if (*it < smallest) {
					smallest = *it;
				}
			}

			return smallest;
		}
	}

}

long double Sample::maximum() {


	long double largest = 0;

	if (get_size() <= 0) {
		return 0;
	} else {

		if (y.begin() == y.end()) {
			cout << "vector is empty " << endl;

			largest = *(y.end());
			return largest;

		} else {

			for (vector<long double>::iterator it = y.begin(); it != y.end(); it++) {

				if (*it > largest) {
					largest = *it;
				}
			}

		}

		return largest;
	}

}

long double Sample::range() {

	if (get_size() > 0) {
		return maximum() - minimum();
	} else {
		return 0;
	}

}

long double Sample::midRange() {

	if (get_size() > 0) {
		return (maximum() + minimum()) / 2.0;
	} else {
		return 0;
	}

}

long double Sample::sum() {

	long double result = 0;

	if (get_size() > 0) {


		for (vector<long double>::iterator it = y.begin(); it != y.end(); it++) {
			result = result + *it;
			//result += *it;
		}

		return result;

	} else {
		return 0;
	}
}

long double Sample::mean() {//also known as average

	if (get_size() > 0) {
		return sum() / get_size();
	} else {
		return 0;
	}

}

long double Sample::calculateAverage(const long double &a, const long double &b) {

	return (a + b) / 2.0;
}

long double Sample::mode() {

	if (get_size() > 0) {

		long double number = *(y.begin());
		long double mode = number;

		int count = 1;
		int countMode = 1;

		for (int i = 1; i < get_size(); i++) {
			if (number == y[i]) {
				count++;
			} else {
				if (count > countMode) {
					countMode = count;
					mode = number;
				}
				count = 1;
				number = y[i];
			}
		}

		return mode;
	} else {
		return 0;
	}
}

long double Sample::variance() {

	if (get_size() > 0) {

		long double result = 0;

		for (vector<long double>::iterator it = y.begin(); it != y.end(); it++) {
			result = result + pow(*it - mean(), 2.0);
		}

		return (result / get_size());//or result/(get_size()-1)

	} else {
		return 0;
	}
}

long double Sample::std_deviation() {
	return sqrt(variance());
}

long double Sample::median() {

	if (get_size() > 0) {

		sort();

		int index = 0;

		if (get_size() % 2 == 0) {
			index = int(get_size() / 2.0);
			//cout << index << " is even    ";
			return calculateAverage(y[index - 1], y[index]);

		} else {
			index = int(get_size() / 2.0) + 1;
			//cout <<  index << " is odd.";
			return y[index - 1];
		}

	} else {
		return 0;
	}

}

void Sample::normalPrint() {

	for(auto vec: y) {
		cout << vec << endl;
	}
}

Sample Sample::print() {

	Sample samplePrint(y);

	cout << "< " << 2 << ": " << flush;

	for (int i = 0; i < samplePrint.y.size(); i++) {
		cout << samplePrint.y[i] << ", " << flush;
	}

	cout << " >" << endl;

	//2
	cout << samplePrint << endl;

	return samplePrint;
}

Sample::~Sample() {
	//cout << "Destructor " << endl;
}

ostream &operator<<(ostream &out, const Sample &sample) {

	out << "Cout Ostream Overload operator of Sample" << endl;

	return out;
}

istream &operator>>(istream &in, const Sample &sample) {

	int i;
	vector<long double> vec;

	do {

		cout << "Enter Values in Vector > " << flush;

		cin >> i;
		vec.push_back(i);

	} while (i < 10);

	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}


	return in;
}

