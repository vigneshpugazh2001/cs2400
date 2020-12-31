# Created by: Nasseef Abukamail
# This Makefile will run tests for the book class
# The tests will run automatically GitHub Actions
# This is to test continuous integration (CI).
# Usage for Mac and Windows:
#    make run_tests_macs 
#    mingw32-make run_tests_win
#
# if make is not availabe on your system, use the following command instead
#  g++ -Wall  _TEST/TEST_cases.cc  book.cc -o  _TEST/run_tests ;  _TEST/run_tests  -sr  compact

#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and
# object files.

a.out: book.o book.h book-library.o
	$(CC) $(CFLAGS) book.o book-library.o -o a.exe

book.o: book.cc book.h
	$(CC) -c $(CFLAGS) book.cc -o book.o

book-library.o: book-library.cc book.h
	$(CC) -c $(CFLAGS) book-library.cc -o book-library.o

################################## DO NOT MODIFY ANYTHING BELOW #####################################
######################################## R U N   T E S T s ##########################################
run_tests: 
	head book.cc
	$(CC) $(CFLAGS) book.cc book-library.cc -o _TEST/a.out
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc book.cc -o _TEST/run_tests ; _TEST/run_tests -sr compact
	sh _TEST/run_tests.sh

# Run the tests under windows using MinGW32-make utility
run_tests_win: 
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc book.cc -o _TEST/run_tests
	_TEST/run_tests -sr compact
######################################################################################################

clean:
#	rm -rf *.o _TEST/*.o _TEST/run_tests a.out _TEST/a.out
	del book.o book-library.o a.exe