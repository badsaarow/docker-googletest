# Makefile
all: fixture_c_c

fixture_c_c: fixture_c_test.cpp fixture_c.c
	g++ -o fixture_c.o -c fixture_c.c -lgcov -fprofile-arcs -ftest-coverage 
	g++ -o fixture_c_test fixture_c.o fixture_c_test.cpp -lgcov -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./fixture_c_test
	gcov -b ./ fixture_c_test.cpp
	lcov -c -d . -o fixture_c_test.lcov --rc lcov_branch_coverage=1
	genhtml fixture_c_test.lcov --rc lcov_branch_coverage=1 -o coverage

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage fixture_c_test