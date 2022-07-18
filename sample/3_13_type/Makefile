# Makefile
all: prime_table

prime_table: TypeTest.cpp prime_tables.h
	g++ -o TypeTest TypeTest.cpp prime_tables.h -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./TypeTest
	gcov -b ./ TypeTest.cpp prime_tables.h -d . -o TypeTest.cpp
	lcov -c -d . -o TypeTest.lcov --rc lcov_branch_coverage=1
	genhtml TypeTest.lcov --rc lcov_branch_coverage=1 -o coverage

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage TypeTest