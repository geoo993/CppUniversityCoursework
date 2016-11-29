#include <iostream>

#include "sample.h"

using namespace std;

int main_test(int argc, char *argv[]) {
	/* an empty sample object - initialise with a vector once
	 * you have defined the sample constructor that takes a
	 * vector
	 */
	//	sample a_sample; // = { 7, 11, 2, 13, 3, 5};
	//	cout << "\tBefore city_test()\n";
	//	city_test(a_sample);
	//	cout << "\tAfter city_test()\n";

	/* Place your code for testing sample after this line. */

	return 0;
}

sample::sample() {
	this -> y.resize(N);
}

sample::sample(vector<long double> y) {
	this -> y = y;

}

sample::sample(const initializer_list<long double>& y)
{
	this -> y = y;
}

sample::sample(const sample &other) {
	this -> y = other.y;
}

sample::sample(sample &&other) {
	this -> y = other.y;
}

sample &sample::operator=(const sample &other) {
	this -> y = other.y;
	return *this;
}

sample &sample::operator=(sample &&other) {
	this -> y = other.y;

	return *this;
}

bool operator==(const sample &l, const sample &r) {
	return l.get_size() == r.get_size();
}

bool operator!=(const sample &l, const sample &r) {
	return !(l.get_size() == r.get_size());
}

bool operator>(const sample &l, const sample &r) {
	return l.get_size() > r.get_size();
}

bool operator>=(const sample &l, const sample &r) {
	return l.get_size() >= r.get_size();
}

bool operator<(const sample &l, const sample &r) {
	return l.get_size() < r.get_size(); // keep the same order
}

bool operator<=(const sample &l, const sample &r) {
	return l.get_size() <= r.get_size();
}

long double &sample::operator[](const unsigned int index) {
	assert(index >= 0 && index < get_size());
	return this -> y[index];

}

const long double &sample::operator[](const unsigned int index) const {
	assert(index >= 0 && index < get_size());
	return this -> y[index];
}

void sample::operator[](vector<long double> y) {
	this -> y = y;
}

void sample::set_sample(string &str, sample &sample) {

	bool colon_mark = false;
	string sizeString;
	string valuesString;

	for (string::iterator it = str.begin(); it != str.end(); ++it) {

		if (*it == '<' || *it == '>') {
			replace(str.begin(), str.end(), *it, ' ');
		} else if (*it == ':') {
			replace(str.begin(), str.end(), *it, ':');
			colon_mark = true;
		} else {

			if (colon_mark == true) {
				valuesString.push_back(*it);
			} else {
				sizeString.push_back(*it);
			}
		}
	}

	stringstream sizeStream(sizeString);
	sizeStream >> sample.N;
	//sample.y.resize(sample.N);

	stringstream sStream(valuesString);
	long double tempDouble;
	while (sStream >> tempDouble)
		sample.insert_data(tempDouble);

}

void sample::set_data(vector<long double> y) {
	this->y = y;
}
void sample::insert_data(long double value) {
	y.push_back(value);
}

vector<long double> sample::get_data() const {
	return y;
}

void sample::sort() {
	::sort(y.begin(), y.end());
}

unsigned int sample::get_size() const {
	return y.size();
}

long double sample::find_data(int index) {

	if (index < get_size()) {
		return y[index];
	} else {
		return 0;
	}
}

long double sample::minimum() {

	long double smallest = N;

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

long double sample::maximum() {

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

long double sample::range() {

	if (get_size() > 0) {
		return maximum() - minimum();
	} else {
		return 0;
	}

}

long double sample::midrange() {

	if (get_size() > 0) {
		return (maximum() + minimum()) / 2.0;
	} else {
		return 0;
	}

}

long double sample::sum() {

	long double result = 0;

	if (get_size() > 0) {

		for (vector<long double>::iterator it = y.begin(); it != y.end(); it++) {
			result = result + *it;
		}

		return result;

	} else {
		return 0;
	}
}

long double sample::mean() {

	if (get_size() > 0) {
		return sum() / get_size();
	} else {
		return 0;
	}

}

long double sample::calculateAverage(const long double &a, const long double &b) {

	return (a + b) / 2.0;
}

long double sample::mode() {

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

long double sample::variance() {

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

long double sample::std_deviation() {
	return sqrt(variance());
}

long double sample::median() {

	if (get_size() > 0) {

		sort();

		int index = 0;

		if (get_size() % 2 == 0) {
			index = int(get_size() / 2.0);

			return calculateAverage(y[index - 1], y[index]);

		} else {
			index = int(get_size() / 2.0) + 1;

			return y[index - 1];
		}

	} else {
		return 0;
	}

}

bool sample::check_unwanted_characters(string &str) {

	for (string::iterator it = str.begin(); it != str.end(); ++it) {

		if (*it != ' ' && *it != '<' && *it != ':' && *it != '>' && !isdigit(
				*it)) {
			return true;
			break;
		}
	}

	return false;

}

void sample::print() const {

	cout << "<" << N << ": " << flush;

	for (int i = 0; i < y.size(); i++) {
		cout << y[i] << " " << flush;
	}

	cout << ">";
}

sample::~sample() {
	//cout << "Destructor " << endl;

}

ostream &operator<<(ostream &out, const sample &sample) {

	//out << "Sample to an output stream, using ostream << Operator Overloading of Sample" << endl;
	//sample.print();

	out << "<" << sample.N << ": " << flush;

	for (int i = 0; i < sample.get_size(); i++) {
		out << sample.y[i] << " " << flush;
	}

	out << ">";

	return out;
}

istream & operator>>(istream &in, sample &sample) {

	sample.y.clear();

	string str;

	cout << "Please Enter values in the Vector >" << flush;

	getline(cin, str);

	if (!sample.check_unwanted_characters(str)) {

		sample.set_sample(str, sample);

		sample.sort();

	} else {
		cout << "Invalid Character" << endl;
	}

	return in;
}

