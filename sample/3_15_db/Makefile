# Makefile
all: test_cpp

test_cpp: Test.cpp
	g++ -o Test Test.cpp -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./Test
	gcov -b ./ Test.cpp -d . -o Test.cpp
	lcov -c -d . -o Test.lcov --rc lcov_branch_coverage=1
	genhtml Test.lcov --rc lcov_branch_coverage=1 -o coverage

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage Test