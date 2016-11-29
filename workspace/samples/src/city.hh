#ifndef _City_HH_
#define _City_HH_

#include <iostream>
#include <vector>

extern int mode;

struct city {
  city ( ) {}
  city ( const std::vector<long double> & data );

  static int has_copy_me;
  virtual city *copy_me() const;
  
};

int main_test(int argc, char *argv[]);

void city_test(city &testing);

#endif
