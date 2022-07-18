# Makefile
all: total_c

total_c: total_test.c total.c
	g++ -o total.o -c total.c -lgcov -fprofile-arcs -ftest-coverage 
	g++ -o total_test total.o total_test.c -lgcov -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./total_test
	gcov -b ./ total_test.c
	lcov -c -d . -o total_test.lcov --rc lcov_branch_coverage=1
	genhtml total_test.lcov --rc lcov_branch_coverage=1 -o coverage

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage total_test