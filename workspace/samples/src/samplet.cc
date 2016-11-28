// You can place the *definitions* of the generic methods here.

#include "samplet.h"

template<typename T>
void swapping(T& t1, T& t2) {
	T tmp(t1); // duplicate t1, making an expensive copy of each element
	t1 = t2; // discard the original contents of t1,
	// and replace them with an expensive duplicate of t2
	t2 = tmp; // discard the original contents of t2,
	// and replace them with an expensive duplicate of tmp
} // implicitly destroy the expensive temporary copy of t1

template<typename T>
samplet<T>::samplet() {
	this -> y.resize(N);
}

template<typename T>
samplet<T>::samplet(vector<T> y) {
	this -> y = y;
}

template<typename T>
samplet<T>::samplet(const samplet &other) {
	this -> y = other.y;
}

template<typename T>
samplet<T>::samplet(samplet &&other) {
	this -> y = other.y;
}

template<typename T>
samplet<T> &samplet<T>::operator=(const samplet<T> &other) {
	y = other.y;
	return *this;
}

template<typename T>
samplet<T> &samplet<T>::operator=(samplet<T> &&other) {
	this -> y = other.y;

	return *this;
}

template<typename T>
T &samplet<T>::operator[](const unsigned int index) // for non-const objects: can be used for assignment
{
	assert(index >= 0 && index < get_size());
	return this -> y[index];

}

template<typename T>
const T &samplet<T>::operator[](const unsigned int index) const // for const objects: can only be used for access
{
	assert(index >= 0 && index < get_size());
	return this -> y[index];
}

template<typename T>
void samplet<T>::operator[](vector<T> y) {
	this -> y = y;
}

template<typename T>
void samplet<T>::set_samplet(string &str, samplet &samplet) {

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
	sizeStream >> samplet.N;

	stringstream sStream(valuesString);
	long double tempDouble;
	while (sStream >> tempDouble)
		samplet.insert_data(tempDouble);

}



template<typename T>
void samplet<T>::set_data(vector<T> y) {
	this->y = y;
}

template<typename T>
vector<T> samplet<T>::get_data() const {
	return y;
}

template<typename T>
void samplet<T>::sort() {
	::sort(y.begin(), y.end());
}

template<typename T>
unsigned int samplet<T>::get_size() const {
	return y.size();
}

template<typename T>
T samplet<T>::find_data(int index) {

	if (index < get_size()) {
		return y[index];
	} else {
		return T();
	}
}

template<typename T>
void samplet<T>::insert_data(T value) {
	y.push_back(value);
}

template<typename T>
T samplet<T>::minimum() {

	T smallest = N;

	if (get_size() <= 0) {
		return T();
	} else {
		if (y.begin() == y.end()) {
			//cout << "vector is empty " << endl;

			smallest = *(y.end());
			return smallest;

		} else {

			for (auto it = y.begin(); it != y.end(); it++) {

				if (*it < smallest) {
					smallest = *it;
				}
			}

			return smallest;
		}
	}

}

template<typename T>
T samplet<T>::maximum() {

	T largest = 0;

	if (get_size() <= 0) {
		return T();
	} else {

		if (y.begin() == y.end()) {
			cout << "vector is empty " << endl;

			largest = *(y.end());
			return largest;

		} else {

			for (auto it = y.begin(); it != y.end(); it++) {

				if (*it > largest) {
					largest = *it;
				}
			}

		}

		return largest;
	}

}

template<typename T>
T samplet<T>::range() {

	if (get_size() > 0) {
		return maximum() - minimum();
	} else {
		return T();
	}

}

template<typename T>
T samplet<T>::midrange() {

	if (get_size() > 0) {
		return (maximum() + minimum()) / 2.0;
	} else {
		return T();
	}

}

template<typename T>
T samplet<T>::sum() {

	T result = 0;

	if (get_size() > 0) {

		for (auto it = y.begin(); it != y.end(); it++) {
			result = result + *it;
			//result += *it;
		}

		return result;

	} else {
		return T();
	}
}

template<typename T>
T samplet<T>::mean() {//also known as average

	if (get_size() > 0) {
		return sum() / get_size();
	} else {
		return T();
	}

}

template<typename T>
T samplet<T>::mode() {

	if (get_size() > 0) {

		T number = *(y.begin());
		T mode = number;

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
		return T();
	}
}

template<typename T>
T samplet<T>::median() {
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
		return T();
	}

}

template<typename T>
T samplet<T>::variance() {

	if (get_size() > 0) {

		T result = 0;

		for (auto it = y.begin(); it != y.end(); it++) {
			result = result + pow(*it - mean(), 2.0);
		}

		return (result / get_size());//or result/(get_size()-1)

	} else {
		return T();
	}
}

template<typename T>
T samplet<T>::std_deviation() {
	return sqrt(variance());
}

template<typename T>
T samplet<T>::calculateAverage(const T &a, const T &b) {

	return (a + b) / 2.0;
}

template<typename T>
void samplet<T>::remove_unwanted_characters(string &str) {

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

template<typename T>
void samplet<T>::print() const {

	cout << "<" << N << ": " << flush;

	for (int i = 0; i < y.size(); i++) {
		cout << y[i] << " " << flush;
	}

	cout << ">";

}

template<typename T>
samplet<T>::~samplet() {
	//cout << "Destructor " << endl;

}



template<typename T>
class samplet<T>::iterator {

private:
	unsigned int pos;
	samplet &m_samplet;

public:
	iterator(unsigned int pos, samplet &s) :
		pos(pos), m_samplet(s) {

	}

	iterator &operator++() //prefix operator implementation
	{
		pos++;
		return *this;
	}
	iterator &operator++(int)//postfix operator implementation
	{
		pos++;
		return *this;
	}

	bool operator!=(const iterator &other) const//not equal operator implementation
	{
		return (pos != other.pos);
	}

	bool operator==(const iterator &other) const//equals operator implementation
	{
		return pos == other.pos;
	}

	T &operator*() {
		return m_samplet.get(pos);
	}

};
