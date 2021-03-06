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
#include <sstream>
#include <cassert>

using namespace std;

template<typename T>
class samplet {

private:
	const int N { 6 };
	vector<T> y;

public:

	samplet();

	samplet(vector<T> y);

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

		int get_N() const;

		void set_data(vector<T> y);

		vector<T> get_data() const;

		void sort();

		unsigned int get_size() const;

		T find_data(int index);

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

		void remove_unwanted_characters(string &str);

		void print() const;

		virtual ~samplet();

		friend ostream &operator<<(ostream &out, const samplet &test);

		friend istream &operator>>(istream &in, samplet &sample);

		class iterator;

		iterator begin() { return iterator(0, *this);}

		iterator end() {return iterator(get_size(), *this);}

	};


//#include "samplet.cpp"

#endif /* SAMPLET_H_ */
