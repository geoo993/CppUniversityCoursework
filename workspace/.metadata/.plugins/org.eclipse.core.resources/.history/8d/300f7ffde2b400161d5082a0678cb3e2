#ifndef _City_HH_
#define _City_HH_

#include <iostream>
#include <vector>

extern int mode;

#define OPERATOR 0

int main_test(int argc, char *argv[]);

template <typename T>
struct cityt {
  cityt ( ) {}
  cityt ( const std::vector<T> & data ) {}
  cityt ( const std::vector<long double> & data ) {}

  virtual cityt<T> *copy_me() const;
  static int has_copy_me;

};

void city_test_generic(cityt<int> &testing);

#endif
