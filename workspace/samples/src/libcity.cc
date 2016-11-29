#include <iostream>
#include <limits>
using namespace std;

#include "city.hh"

enum class in_mode { run = 0, test = 1, mark = 2};
int mode = (int) in_mode::run;

int city::has_copy_me = true;
city *city::copy_me() const {
  city::has_copy_me = false;
  return new city(*this);
}

#include <sstream>
#include <utility>
#include <string>
void city_test_c(const city &testing) {
  city tmp = testing;
  tmp = tmp;
}

pair<bool, string> check_exists( bool plain, bool constant, string method ) {
  return {(plain || constant),
      method + ((plain && !constant)
		? " but check its signature/declaration"
		: "")};
}

int city_test_executed = 0;
void city_test(city &testing) {
  city_test_executed = 1;

  city_test_c(testing);
}

int main(int argc, char *argv[]) {
  int result = -1;
  try {
    result = main_test(argc, argv);
    if (!city_test_executed)
      cout << "\tYou need to call city_test() inside your main_test(),\npassing it a sample object as a parameter\n\tMarks: 0/100.\n";
  } catch (...) {
    throw;
  }
  
  return result;
}
