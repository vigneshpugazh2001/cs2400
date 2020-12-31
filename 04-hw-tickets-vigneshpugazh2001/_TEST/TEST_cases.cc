/*
 * Unit testing for the integer homework
 */
//#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include "NO_MAIN.cc"

#include "catch.hpp"

const int MAX_SCORE = 5;
const int NUM_TESTS = 1;
static int score = 0;
static int testsPassed = 0;

TEST_CASE("Testing isValid functions") {

    SECTION("isValid"){
        REQUIRE(true == isValid("ab123456"));
        REQUIRE(true == isValid("Ab345091"));
        REQUIRE(true == isValid("AB999999"));
        REQUIRE(false == isValid("0"));
        REQUIRE(false == isValid("ab1234567"));
        REQUIRE(false == isValid("ab123A56"));
        REQUIRE(false == isValid("ab23"));
        REQUIRE(false == isValid("123456ab"));
        
        score += 5;
        testsPassed++;
    }

    SECTION("Score"){
        cout << "\n==========================================" << endl;
        cout << "\033[1;33m" <<  " Score: " << score << "/" << MAX_SCORE << "\033[1;35m"
        << " (passed " << testsPassed <<  " out of " << NUM_TESTS << " tests)" << "\033[0m" << endl;
        cout << "==========================================\n" << endl;
    }
}

