#ifndef _SAMPLET_H_
#define _SAMPLET_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <initializer_list>
#include <fstream>//file stream

using namespace std;


template<typename T>
class samplet {

public:
	vector<T> y;

	samplet();

	samplet(vector<T> y);

	samplet(const initializer_list<T> &y);

	samplet(const samplet &other);

	samplet(samplet &&other);

	samplet &operator=(const samplet &other);

	samplet &operator=(samplet &&other);

	friend bool operator== (const samplet &l, const samplet &r) {
		return l.get_size() == r.get_size();
	}

	friend bool operator!= (const samplet &l, const samplet &r) {
		return !(l.get_size() == r.get_size());
	}

	friend bool operator> (const samplet &l, const samplet &r) {
		return l.get_size() > r.get_size();
	}

	friend bool operator>= (const samplet &l, const samplet &r)
	{
		return l.get_size() >= r.get_size();
	}

	friend bool operator< (const samplet &l, const samplet &r) {
		return l.get_size() < r.get_size(); // keep the same order
		}

		friend bool operator<= (const samplet &l, const samplet &r) {
			return l.get_size() <= r.get_size();
		}

		T &operator[](const unsigned index); // for non-const objects: can be used for assignment

		const T &operator[](const unsigned index) const; // for const objects: can only be used for access

		void operator[] (vector<T> y);

		void set_samplet(string &str, samplet &samplet);

		void set_data(vector<T> y);

		vector<T> get_data() const;

		void sort();

		unsigned int get_size() const;

		unsigned int N() const;

		T find_data(unsigned int index);

		void insert_data(T value);

		T minimum();

		T maximum();

		T range();

		T midrange();

		T sum();

		T mean();

		T mode();

		T median();

		T variance();

		T std_deviation();

		T calculateAverage(const T &a, const T &b);

		bool check_unwanted_characters(string &str);

		friend ostream &operator<<(ostream &out, const samplet<T> &samplet) {

			//out << "Sample to an output stream, using ostream << Operator Overloading of Samplet" << endl;
			samplet.print(out);

			return out;
		}

		friend istream &operator>>(istream &in, samplet<T> &samplet) {

			string str;
			cout << "Please Enter values in the Template Vector >" << flush;

			getline(cin, str);

			samplet.compute_set_sample(str, samplet);

			return in;
		}

		void print(ostream &out) const;

		void compute_set_sample(string &str, samplet &samplet) const;

		void test(samplet &samplet, fstream &outputStream) const;

		class iterator;

		iterator begin() {return iterator(0, *this);}

		iterator end() {return iterator(get_size(), *this);}

		virtual ~samplet();

	};

//#include "samplet.cc"

#endif
