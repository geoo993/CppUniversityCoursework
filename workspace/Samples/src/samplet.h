/*
 * samplet.h
 *
 *  Created on: 8 Nov 2016
 *      Author: GeorgeQuentin
 */

#ifndef SAMPLET_H_
#define SAMPLET_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

template<typename T>
class Samplet {
private:
	int input;
	const int N { 100 };
	vector<T> y;

public:

	Samplet() :
		input(T()) {
		//cout << "Constructor " << endl;
		y.resize(N);
	}

	Samplet(vector<T> y) {
		//cout << "Constructor with Parameters" << endl;
		this -> y.resize(N);
		this -> y = y;

		input = T();
	}

	Samplet(const Samplet &other) {
		//cout << "Copy Constructor" << endl;
		y = other.y;
		input = other.input;
	}

	Samplet(Samplet &&other) {
		//cout << "Move Copy Constructor" << endl;
			y = other.y;
			input = other.input;
		}

		Samplet &operator=(const Samplet &other)
		{
			//cout << "Assignment Constructor" << endl;
			y = other.y;

			return *this;
		}

		Samplet &operator=(Samplet &&other) {
			//cout << "Move Assignment Constructor" << endl;
			y = other.y;

			return *this;
		}

		int get_N() {
			return this->N;
		}

		void set_data(vector<T> y) {
			this->y = y;
		}

		vector<T> get_data() {
			return y;
		}

		void sort() {//ascending order
			::sort(y.begin(), y.end());
		}

		int get_size() {
			return y.size();
		}

		T find_data(int index) {

			if (index < get_size()) {
				return y[index];
			} else {
				return T();
			}
		}

		T minimum() {

			T smallest = get_N();

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


		T maximum() {

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


		T range() {

			if (get_size() > 0) {
				return maximum() - minimum();
			} else {
				return T();
			}

		}

		T midRange() {

			if (get_size() > 0) {
				return (maximum() + minimum()) / 2.0;
			} else {
				return T();
			}

		}

		T sum() {

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

		T mean() {//also known as average

			if (get_size() > 0) {
				return sum() / get_size();
			} else {
				return T();
			}

		}

		T mode() {

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



		T median() {
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




		T variance() {

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

		T std_deviation() {
			return sqrt(variance());
		}

		T calculateAverage(const T &a, const T &b) {

			return (a + b) / 2.0;
		}

		void normalPrint() {

			for(auto vec: y) {
				cout << vec << endl;
			}
		}

		Samplet print() {

			Samplet samplePrint(y);

			cout << "< " << 6 << ": " << flush;

			for (int i = 0; i < samplePrint.y.size(); i++) {
				cout << samplePrint.y[i] << ", " << flush;
			}

			cout << " >" << endl;

			//2
			cout << samplePrint << endl;

			return samplePrint;
		}

		~Samplet() {
			//cout << "Destructor " << endl;
		}

		friend ostream &operator<<(ostream &out, const Samplet &test) {
			out << "Cout Ostream Overload operator of Samplet" << endl;

			return out;
		}

		friend istream &operator>>(istream &in, const Samplet &sample) {
			int i;
			vector<T> vec;

			do {

				cout << "Enter Values in Vector > " << flush;

				cin >> i;
				vec.push_back((T)(i));

			}while (i < 15);

			for (int i = 0; i < vec.size(); i++) {
				cout << vec[i] << " ";
			}
			return in;
		}

		class iterator;

		iterator begin() {
			return iterator(0, *this);
		}
		iterator end() {
			return iterator(get_size(), *this);
		}

};



template<typename T>
class Samplet<T>::iterator {

private:
	unsigned int pos;
	Samplet &m_samplet;

public:
	iterator(unsigned int pos, Samplet &s) :
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

#endif /* SAMPLET_H_ */
