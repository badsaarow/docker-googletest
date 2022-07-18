# Makefile
all: my_math_c

my_math_c: my_math_test.c my_math.c
	g++ -o my_math.o -c my_math.c -lgcov -fprofile-arcs -ftest-coverage 
	g++ -o my_math_test my_math.o my_math_test.c -lgcov -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./my_math_test
	gcov -b ./ my_math_test.c
	lcov -c -d . -o my_math_test.lcov --rc lcov_branch_coverage=1
	genhtml my_math_test.lcov --rc lcov_branch_coverage=1 -o coverage

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage my_math_test