/*
 * sample.cpp
 *
 *  Created on: 4 Nov 2016
 *      Author: GeorgeQuentin
 */

#include "sample.h"

Sample::Sample() {
	cout << "Constructor " << endl;
	y.resize(N);
}

Sample::Sample(vector<long double> y) {
	cout << "Constructor with Parameters" << endl;
	this -> y.resize(N);
	this -> y = y;

}

Sample::Sample(const Sample &other) {//copy constructor
	cout << "Copy Constructor" << endl;
	this -> y = other.y;
}

Sample::Sample(Sample &&other) { //this is a move copy constructor, usually you do not need const in R values references

	cout << "Move Copy Constructor" << endl;
	this -> y = other.y;
}

Sample &Sample::operator=(const Sample &other)//assignment constructor
{
	cout << "Assignment Constructor" << endl;
	this -> y = other.y;
	return *this;
}

Sample &Sample::operator=(Sample &&other) {// this is the move assignment operator

			cout << "Move Assignment Constructor" << endl;
			this -> y = other.y;

			return *this;
		}

bool operator==(const Sample &l, const Sample &r) {
	return l.get_size() == r.get_size();
}

bool operator!=(const Sample &l, const Sample &r) {
	return !(l.get_size() == r.get_size());
}

bool operator>(const Sample &l, const Sample &r) {
	return l.get_size() > r.get_size();
}

bool operator>=(const Sample &l, const Sample &r) {
	return l.get_size() >= r.get_size();
}

bool operator<(const Sample &l, const Sample &r) {
	return l.get_size() < r.get_size(); // keep the same order
}

bool operator<=(const Sample &l, const Sample &r) {
	return l.get_size() <= r.get_size();
}

long double &Sample::operator[](const unsigned int index) // for non-const objects: can be used for assignment
{
	assert(index >= 0 && index < get_size());
	return this -> y[index];

}

const long double &Sample::operator[](const unsigned int index) const // for const objects: can only be used for access
{

//	if (index < get_size()) {
//		return this -> y[index];
//	} else {
//		return this -> y.back();
//	}

	assert(index >= 0 && index < get_size());
	return this -> y[index];
}

void Sample::operator[] (vector<long double> y)
{
	this -> y = y;
}


int Sample::get_N() const {
	return this->N;
}

void Sample::set_data(vector<long double> y) {
	this->y = y;
}
void Sample::insert_data(long double value) {
	y.push_back(value);
}
//3
vector<long double> Sample::get_data() const {
	return y;
}

void Sample::sort() {
	::sort(y.begin(), y.end());
}

unsigned int Sample::get_size() const {
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

long double Sample::midrange() {

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

void Sample::remove_unwanted_characters(string &str) {

	string fstring;
	for (string::iterator it = str.begin(); it != str.end(); ++it) {

		if (isdigit(*it)) {
			fstring.push_back(*it);
		} else if (*it == ' ') {
			fstring.push_back(*it);
		}

		//		if (!isdigit(*it)) {
		//			replace(str.begin(), str.end(), *it, ' ');
		//		}

	}
	str = fstring;
	//cout << str << " " << fstring << "\n";

}

void Sample::print() const{

	cout << "<" << y.size() << ": " << flush;

	for (int i = 0; i < y.size(); i++) {
		cout << y[i] << " " << flush;
	}

	cout << ">" ;
}

Sample::~Sample() {
	//cout << "Destructor " << endl;

}

ostream &operator<<(ostream &out, const Sample &sample) {

	//out << "Sample to an output stream, using ostream << Operator Overloading of Sample" << endl;
	sample.print();

	return out;
}

istream & operator>>(istream &in, Sample &sample) {

	sample.y.clear();

	string str;

	cout << "Please Enter " << sample.get_N() << " Values in Vector >" << flush;

	getline(cin, str);

	//sample.remove_unwanted_characters(str);

	stringstream sStream(str);
	long double tempDouble;

	while (sStream >> tempDouble)
		sample.insert_data(tempDouble);

	return in;
}

