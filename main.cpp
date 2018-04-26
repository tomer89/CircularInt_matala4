#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "CircularInt.hpp"
#include "catch.hpp"

std::string cirToString(const CircularInt &circularInt)
{
    std::stringstream ss;
    ss << circularInt ;
    return ss.str();
}
TEST_CASE("submit","-")
{
    CircularInt hour {1, 12};
    hour = hour - 3;
    REQUIRE(cirToString(hour) == "10");
    CircularInt hour2 {1, 12};
    hour2 = 2 - hour ;
    REQUIRE(cirToString(hour2) == "4");
    hour = hour - hour2 ;
    REQUIRE(cirToString(hour) == "6");
}














/*#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "CircularInt.hpp"
#include "catch.hpp"

std::string cirToString(const CircularInt &circularInt)
{
    std::stringstream ss;
    ss << circularInt ;
    return ss.str();
}

TEST_CASE("equals","==")
{
    CircularInt hour {1, 10};
    CircularInt hour2 {1, 10};
    bool test1 = (hour == hour2);
    REQUIRE(test1);
    REQUIRE(hour == 1 );
    REQUIRE( 1 == hour );
}
*/










/*#include <iostream>
using namespace std;

#include "CircularInt.hpp"

/**
 * for internal use:
 *for compiling use:         g++ -std=c++0x main.cpp CircularInt.cpp
 * All operators:            https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
 * For deeper understanding: read this: https://stackoverflow.com/questions/8293426/error-invalid-initialization-of-non-const-reference-of-type-int-from-an-rva
 * course github:            https://github.com/erelsgl/ariel-cpp-5778/tree/master/week04-operator-overloading/homework
 * automatic check:          http://31.154.73.178:8006/?backend=5676&exercise=EX2
 * My git:                   https://github.com/tomer89/CircularInt_matala4.git
*/

/*
int main() {
	CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;     // 8
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	cout << hour+hour << endl;                // 10 (11 hours after 11)
	
	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	//hour *= -2;   cout << hour << endl;       // 10 (10*2 = 10+10 = 20 = 8)
	//hour *= 0; cout <<hour << endl;           //0
	cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

	try {
		cout << hour/3;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}
	





	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}*/