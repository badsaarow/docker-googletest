# Makefile
all: mock_c

mock_c: mock_c_test.cpp mock_c.c
	g++ -o mock_c.o -c mock_c.c -lgcov -fprofile-arcs -ftest-coverage 
	g++ -o mock_c_test mock_c.o mock_c_test.cpp -lgcov -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./mock_c_test
	gcov -b ./ mock_c_test.cpp
	lcov -c -d . -o mock_c_test.lcov --rc lcov_branch_coverage=1
	genhtml mock_c_test.lcov --rc lcov_branch_coverage=1 -o coverage

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage mock_c_test