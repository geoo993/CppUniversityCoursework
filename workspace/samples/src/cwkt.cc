#include <iostream>
#include <fstream>//file stream
#include "samplet.h"

using namespace std;

int main_test(int argc, char *argv[]) {
	/* an empty samplet object - initialise with a vector once
	 * you have defined the samplet constructor that takes a
	 * vector
	 */
	samplet<int> a_samplet; // = { 7, 11, 2, 13, 3, 5 };
	cout << "\tBefore city_test_generic()\n";
	city_test_generic(a_samplet);
	cout << "\tAfter city_test_generic()\n";
	/* Place your code for testing samplet after this line. */

    
    string outputFile = "cwk-input01.txt";
    
    fstream outFile;
    outFile.open(outputFile, ios::out);
    
    if (outFile.is_open()) {
        
        while (cin >> a_samplet)
            
            //2
            outFile << "George Quentin C++ Cousework 2016." << endl
            
            <<  a_samplet << endl
            
            //3
            << "Size: " << a_samplet.get_size() << endl
            
            //4
            << "Smallest number: " << a_samplet.minimum() << endl
            
            //5
            << "Largest number: " << a_samplet.maximum() << endl
            
            //6
            << "Range: " << a_samplet.range() << endl
            
            //7
            << "Mid-Range: " << a_samplet.midrange() << endl
            
            //11
            << "Median: " << a_samplet.median() << endl
            
            //8
            << "Sum: " << a_samplet.sum() << endl
            
            << "Mean: " << a_samplet.mean() << endl
            
            //9
            << "Variance: " << a_samplet.variance() << endl
            
            << "Mode: " << a_samplet.mode() << endl
            
            //10
            << "Standard Deviation: " << a_samplet.std_deviation() << endl << endl
            
            << "The output is written in ---> " << outputFile  << endl;
        
        if (cin.bad())
            cerr << "\nBad input\n\n";
        
        outFile.close();
        
    } else { cerr << "Could not create file " << outputFile << endl; }
    
    
    
    
	return 0;
}
