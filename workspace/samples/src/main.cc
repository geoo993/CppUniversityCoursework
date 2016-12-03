#include "sample.h"
#include "samplet.h"
#include "samplet.cc"

using namespace std;


int stringToInt(string str) {

	const char* characters = str.c_str();

	int value = 0;
	for (int i = 0; i < strlen(characters); i++) {
		value = value + (int) characters[i];
	}

	return value;
}

int main(int argc, char *argv[]) {

	//sample a_sample;
	//samplet<long double> a_sample;
	//samplet<double> a_sample;
	samplet<float> a_sample;
	//samplet<int> a_sample;


	//<6: 7 11 2 13 3 5 >
//	string special_str = "<2: 1.18973e+4932 1.18973e+4932 >";
	string text_file_name = "cwk-input01.txt";
	fstream outFile;
	outFile.open(text_file_name, ios::out);

	cout << "Please Enter values in the Vector >" << flush;

	 while (cin >> a_sample){

		 //this code for testing sample file and writing the result into a text file
		 a_sample.test(a_sample, text_file_name, outFile);

		 outFile.close();

	 }
	 if (cin.bad())
		 cerr << "\nBad input\n\n";


	return 0;
}
