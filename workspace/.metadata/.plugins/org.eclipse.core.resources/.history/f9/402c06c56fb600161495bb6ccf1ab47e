#include <iostream>
#include <limits>
using namespace std;

#include "cityt.hh"

enum class in_mode { run = 0, test = 1, mark = 2};
int mode = (int) in_mode::run;

pair<bool, string> check_exists( bool plain, bool constant, string method ) {
  return {(plain || constant),
      method + ((plain && !constant)
		? " but check its signature/declaration"
		: "")};
}

#include <sstream>
#include <utility>
#include <string>
void city_test_generic_c(const cityt<int> &testing) {
}

int city_test_executedt = 0;
void city_test_generic(cityt<int> &testing) {
  city_test_executedt = 1;
  cityt<int> tmp = testing;
  
  city_test_generic_c(tmp);
}

int main(int argc, char *argv[]) {
  int result = -1;
  try {
    result = main_test(argc, argv);
    if (!city_test_executedt)
      cout << "\tYou need to call city_test_generic() inside your main_test(),\npassing it a samplet<int> object as a parameter\n\tMarks: 0/100.\n";
  } catch (...) {
    throw;
  }
  
  return result;
}
